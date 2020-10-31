/*
** EPITECH PROJECT, 2019
** Library
** File description:
** Get next line
*/

#include "get_next_line.h"

char *re_alloc_str(char *str, int size)
{
    int i = 0;
    char *result = malloc(sizeof(char) * size);

    if (!result)
        return (NULL);
    for (; str[i]; i++)
        result[i] = str[i];
    free(str);
    for (; i < size; i++)
        result[i] = 0;
    return (result);
}

char *load_buffer(int fd, int *size, char *buffer, int *i)
{
    static int last_fd = -1;

    if (last_fd != fd || (*i >= *size)) {
        buffer = malloc(sizeof(char) * (READ_SIZE + 1));
        buffer[READ_SIZE] = 0;
        if (!buffer)
            return (NULL);
        *size = read(fd, buffer, READ_SIZE);
        *i = 0;
    }
    if (*size == -1)
        return (NULL);
    last_fd = fd;
    return (buffer);
}

char *clear_str(char *str)
{
    for (int i = 0; i < READ_SIZE; str[i] = 0, i++);
    return (str);
}

char *read_input(int fd, int *i, int *count, char *result)
{
    static char *buff = NULL;
    static int size = READ_SIZE;

    if ((buff = load_buffer(fd, &size, buff, i)) == NULL)
        return (NULL);
    for (int j = 0; size && buff[*i] != '\n'; (*i)++, j++) {
        if (*i >= size) {
            buff = clear_str(buff);
            size = read(fd, buff, READ_SIZE);
            result = re_alloc_str(result, j + size + 1);
            (*i = -1, j--);
        } else {
            result[j] = buff[*i];
            (*count)++;
        }
        if (size == -1)
            return (NULL);
    }
    (buff[*i] == '\n') ? (*count)++ : 0;
    return (result);
}

char *get_next_line(int fd)
{
    static int i = 0;
    int j = 0;
    char *result = NULL;

    if (fd < 0)
        return (NULL);
    result = malloc(sizeof(char) * (READ_SIZE + 1));
    if (!result)
        return (NULL);
    for (int k = 0; k <= READ_SIZE; result[k] = 0, k++);
    result = read_input(fd, &i, &j, result);
    if (!j)
        return (NULL);
    i++;
    return (result);
}

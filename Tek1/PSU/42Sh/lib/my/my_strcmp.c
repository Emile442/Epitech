/*
** EPITECH PROJECT, 2019
** Library
** File description:
** My str compare
*/

#include <my.h>

int my_strcmp(char const *str_1, char const *str_2)
{
    int state = 1;
    int i = 0;

    for (; str_1[i] && str_2[i] && state; i++) {
        if (str_1[i] != str_2[i])
            state = 0;
    }
    if (str_1[i] || str_2[i])
        state = 0;
    return (state);
}

int my_strncmp(char const *str_1, char const *str_2, int n)
{
    int state = 1;
    int i = 0;

    for (; str_1[i] && str_2[i] && state && i < n; i++) {
        if (str_1[i] != str_2[i])
            state = 0;
    }
    if (i != n)
        state = 0;
    return (state);
}

char *my_strcpy(char *str)
{
    char *new_str;
    int i = 0;

    new_str = malloc(sizeof(char) * (my_strlen(str) + 1));
    for (; str[i]; i++)
        new_str[i] = str[i];
    new_str[i] = 0;
    return (new_str);
}

char *my_strncpy(char *str, int nb)
{
    char *new_str = NULL;

    if (nb <= 0)
        return (NULL);
    new_str = malloc(sizeof(char) * (nb + 1));
    if (!new_str)
        return (NULL);
    for (int i = 0; i <= nb; new_str[i] = 0, i++);
    for (int i = 0; i < nb && str[i]; i++)
        new_str[i] = str[i];
    return (new_str);
}

char *my_strcat(char *dest, char *str)
{
    char *result;
    int len;
    int count = 0;

    len = my_strlen(dest) + my_strlen(str) + 1;
    result = malloc(sizeof(char) * len);
    for (int i = 0; dest[i]; i++, count++)
        result[count] = dest[i];
    for (int i = 0; str[i]; i++, count++)
        result[count] = str[i];
    result[len - 1] = 0;
    return (result);
}

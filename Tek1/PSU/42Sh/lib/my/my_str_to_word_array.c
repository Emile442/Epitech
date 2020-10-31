/*
** EPITECH PROJECT, 2019
** My str to word array
** File description:
** take char * to a char **
*/

#include <my.h>

char **my_strarraycpy(char **array)
{
    char **cpy;
    int len = my_strarray_len(array);

    cpy = malloc(sizeof(char *) * len + 1);
    if (!cpy)
        return (NULL);
    for (int i = 0; i < len; i++)
        cpy[i] = my_strcpy(array[i]);
    cpy[len] = 0;
    return (cpy);
}

char **malloc_each_word(char *str, char **word_array, int count)
{
    int *count_char = malloc(sizeof(int) * count);

    if (!count_char)
        return (NULL);
    for (int i = 0; i < count; i++)
        count_char[i] = 0;
    for (int i = 0, j = 0; str[i] && j < count; i++) {
        if ((str[i] == ' ' || str[i] == '\t') &&
            (str[i - 1] != ' ' && str[i - 1] != '\t') && i)
            j++;
        else if (str[i] != ' ' && str[i] != '\t')
            count_char[j]++;
    }
    for (int i = 0; i < count; i++) {
        word_array[i] = malloc(sizeof(char) * (count_char[i] + 1));
        if (!word_array[i])
            return (NULL);
        word_array[i][count_char[i]] = 0;
    }
    return (word_array);
}

char **malloc_word_array(char *str)
{
    char **word_array;
    int i = 0;
    int count = 1;

    for (;str[i]; i++) {
        if ((str[i] == ' ' || str[i] == '\t')
            && (str[i - 1] != ' ' && str[i - 1] != '\t') && i)
            count++;
    }
    (str[i - 1] == ' ' || str[i - 1] == '\t') ? count-- : 0;
    if (!count)
        return (NULL);
    word_array = malloc(sizeof(char *) * (count + 1));
    if (!word_array)
        return (NULL);
    word_array[count] = NULL;
    word_array = malloc_each_word(str, word_array, count);
    return (word_array);
}

char **my_str_to_word_array(char *str)
{
    char **word_array;

    word_array = malloc_word_array(str);
    if (!word_array)
        return (NULL);
    for (int i = 0, j = 0, k = 0; str[i]; i++) {
        if ((str[i] == ' ' || str[i] == '\t')
        && (str[i - 1] != ' ' && str[i -1] != '\t') && i) {
            k = 0;
            j++;
        }
        else if (str[i] != ' ' && str[i] != '\t') {
            word_array[j][k] = str[i];
            k++;
        }
    }
    return (word_array);
}

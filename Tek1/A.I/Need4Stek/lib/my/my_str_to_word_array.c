/*
** EPITECH PROJECT, 2018
** my_str_to_word_array
** File description:
** str to array
*/

#include "my.h"

bool is_separator(char const *separators, char c)
{
    for (int i = 0; separators[i]; i++) {
        if (separators[i] == c)
            return (true);
    }
    return (false);
}

int count_array_size(char const *str, char const *separators)
{
    int i = 0;
    int size = 0;

    for (; str[i]; i++) {
        if (is_separator(separators, str[i]) == true && \
is_separator(separators, str[i + 1]) == false)
            size++;
    }
    return (size + 1);
}

int get_word_size(char const *str, int *n, char const *separators)
{
    int len = 0;

    for (; is_separator(separators, str[(*n)]) == true; (*n) = (*n) + 1);
    for (; str[(*n)] != '\0'; (*n) = (*n) + 1) {
        if (is_separator(separators, str[(*n)]) == true)
            return (len);
        len++;
    }
    return (len);
}

char **malloc_word_array(char const *str, char **array, char const *separators)
{
    int i = 0;
    int nbr = count_array_size(str, separators);
    int len = 0;
    int n = 0;

    array = malloc(sizeof(char *) * (nbr + 1));
    if (!array)
        return (NULL);
    while (i < nbr) {
        len = get_word_size(str, &n, separators);
        array[i] = my_strset((len + 1), ' ');
        if (!array[i])
            return (NULL);
        len = 0;
        i++;
    }
    return (array);
}

char **my_str_to_word_array(char const *str, char const *separators)
{
    int i = 0;
    int m = 0;
    int n = 0;
    char **array = NULL;

    array = malloc_word_array(str, array, separators);
    for (; is_separator(separators, str[i]) == true; i++);
    for (; str[i]; i++, n++) {
        if (is_separator(separators, str[i]) == false)
            array[m][n] = str[i];
        if (is_separator(separators, str[i]) == true &&
        is_separator(separators, str[i + 1]) == false) {
            array[m][n] = '\0';
            m++;
            n = -1;
        }
    }
    array[m][n] = '\0';
    array[m + 1] = NULL;
    return (array);
}

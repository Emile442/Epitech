/*
** EPITECH PROJECT, 2019
** minishell
** File description:
** my_str_to_word_array_bis
*/

#include <stdlib.h>
#include "my.h"

int separator(char c, char split)
{
    if (c == split || c == '\n' || c == '\t' || c == '\0')
        return (1);
    return (0);
}

int how_many_words(char *str, char split)
{
    int count_word = 1;

    for (int i = 0; str[i]; i++) {
        if (separator(str[i], split) == 1)
            count_word++;
    }
    return (count_word);
}

char **my_str_to_word_array_bis(char split, char *str)
{
    char **array = malloc(sizeof(char*) * (how_many_words(str, split) + 1));
    int count_letters = 0;
    int j = 0;

    for (int i = 0; str[i]; i++) {
        if (separator(str[i], split) == 0)
            count_letters++;
        if (separator(str[i], split) == 0 \
&& separator(str[i + 1], split) == 1) {
            array[j] = malloc(sizeof(char) * (count_letters + 1));
            array[j] = my_strncpy\
(array[j], &str[i - count_letters + 1], count_letters);
            j++;
            count_letters = 0;
        }
    }
    array[j] = NULL;
    return (array);
}

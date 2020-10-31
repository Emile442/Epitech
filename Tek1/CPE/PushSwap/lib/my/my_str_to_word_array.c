/*
** EPITECH PROJECT, 2018
** my_str_to_word_array
** File description:
** Split a strings into words
*/

#include <stdlib.h>

int my_show_word_array(char * const *tab);
char *my_strncpy(char *dest, char *src, int n);

static int is_alphanum(char c)
{
    return ((c <= 32 || c >= 127) ? 0 : 1);
}

static int word_c(char *str)
{
    int w = 0;

    for (int i = 0; str[i]; i++)
        if (is_alphanum(str[i]) && !is_alphanum(str[i + 1]))
            w++;
    return (w);
}

char **my_str_to_word_array(char *str)
{
    int j = 0;
    int len = 0;
    char **tmp = malloc(sizeof(char *) * (word_c(str) + 1));

    if (tmp == NULL)
        return (NULL);
    for (int i = 0; str[i]; i++) {
        if (is_alphanum(str[i]))
            len++;
        if (is_alphanum(str[i]) && !is_alphanum(str[i + 1])) {
            tmp[j] = malloc(len + 1);
            my_strncpy(tmp[j], &str[i - len + 1], len);
            len = 0;
            j++;
        }
    }
    tmp[j] = NULL;
    return (tmp);
}
/*
** EPITECH PROJECT, 2018
** parse_str
** File description:
** Split a strings with delimiter
*/

#include <stdlib.h>
#include <stdlib.h>
#include <stdbool.h>

static bool is_char(char s, char c)
{
    if (s == c)
        return (true);
    return (false);
}

static int word_c(char *str, char c)
{
    int w = 1;

    for (int i = 0; str[i]; i++)
        if (is_char(str[i], c))
            w++;
    return (w);
}

static int word_length(char* str, char c)
{
    int i = 0;

    for (; is_char(str[i], c); i++)
        i++;
    return (i);
}

char **parse_str(char *str, char c)
{
    int	i = word_length(str, c);
    int j = 0;
    char **tmp = malloc(sizeof(char *) * word_c(str, c) + 1);

    for (int word = 0; str[i] != 0;) {
        tmp[j] = malloc(sizeof(char) * word_length(&str[i], c) + 1);
        for (word = 0; str[i] && !is_char(str[i], c); word++, i++)
            tmp[j][word] = str[i];
        tmp[j++][word] = '\0';
        for (; is_char(str[i], c); i++);
    }
    tmp[j] = NULL;
    return (tmp);
}

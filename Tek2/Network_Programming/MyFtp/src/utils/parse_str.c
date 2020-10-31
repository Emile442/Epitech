/*
** EPITECH PROJECT, 2018
** parse_str
** File description:
** Split a strings with delimiter
*/

#include <stdlib.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

static bool is_char(char s, char c)
{
    return (s == c);
}

static int word_c(char *str, char c)
{
    int w = 1;

    for (int i = 0; str && str[i]; i++)
        if (is_char(str[i], c))
            w++;
    return (w);
}

static int word_length(char* str, char c)
{
    int i = 0;

    for (; str && is_char(str[i], c); i++)
        i++;
    return (i);
}

char **parse_str(char *str, char c)
{
    char *str_tmp = strtok(str, "\r\n");
    int	i = word_length(str_tmp, c);
    int j = 0;
    char **tmp = malloc(sizeof(char *) * word_c(str_tmp, c) + 1);

    if (!str_tmp)
        return (tmp);
    for (int word = 0; str_tmp[i] != 0;) {
        tmp[j] = malloc(sizeof(char) * word_length(&str_tmp[i], c) + 1);
        for (word = 0; str_tmp[i] && !is_char(str_tmp[i], c); word++, i++)
            tmp[j][word] = str_tmp[i];
        tmp[j++][word] = '\0';
        for (; is_char(str_tmp[i], c); i++);
    }
    tmp[j] = NULL;
    return (tmp);
}

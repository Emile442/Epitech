/*
** EPITECH PROJECT, 2019
** errors.c
** File description:
** check_file.c
*/

#include "my.h"
#include "parsing.h"
#include <stddef.h>

int is_valid_node(char *line)
{
    int i = 0;

    if (!line || count_words(line) != 3)
        return (0);
    while (line[i] != ' ')
        i++;
    while (line[i] == ' ')
        i++;
    while (line[i] >= '0' && line[i] <= '9')
        i++;
    if (line[i] != ' ')
        return (0);
    while (line[i] == ' ')
        i++;
    while (line[i] >= '0' && line[i] <= '9')
        i++;
    if (line[i] != 0 && line[i] != ' ')
        return (0);
    return (1);
}

int check_empty_line(char **file, int i, int check)
{
    static int start = 0;
    static int end = 0;

    if (check) {
        if (start && end)
            return (1);
        return (0);
    }
    if (my_strcmp(file[i], "##start")) {
        if (!is_valid_node(file[i + 1]))
            return (1);
        start++;
    }
    else if (my_strcmp(file[i], "##end")) {
        if (!is_valid_node(file[i + 1]))
            return (1);
        end++;
    }
    if (start > 1 || end > 1)
        return (1);
    return (0);
}

int is_valid_link(char *file, int check)
{
    int dash = 0;
    int j = 0;
    static int valid = 0;

    if (check)
        return (valid);
    for (int i = 0; file[i]; i++)
        if (file[i] == '-')
            dash++;
    if (dash != 1)
        return (0);
    while (file[j] != '-')
        j++;
    if (j == 0 || !file[j + 1])
        return (0);
    valid++;
    return (1);
}

int is_comment(char *line)
{
    int i = 0;
    if (my_strcmp(line, "##start"))
        return (3);
    else if (my_strcmp(line, "##end"))
        return (2);
    if (line[0] == '#')
        return (1);
    while (line[i] && line[i] != '#')
        i++;
    line[i] = 0;
    return (0);
}

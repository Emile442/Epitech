/*
** EPITECH PROJECT, 2020
** zappy
** File description:
** cmd_parsing
*/

#include "zappy_ai.h"

int count_c(const char* str, char c)
{
    int rt = 0;
    for (int i = 0; str[i]; i++)
        if (str[i] == c)
            rt++;
    return (rt);
}

char** parse_str(const char* str)
{
    char** rt = calloc(count_c(str, ' ') + 2, sizeof(char*));
    char* copy = strdup(str);
    char* tmp = strtok(copy, " ");

    rt[0] = NULL;
    for (int i = 0; tmp != NULL; i++, tmp = strtok(NULL, " ")) {
        rt[i] = strdup(tmp);
        if (rt[i][strlen(rt[i]) - 1] == '\n')
            rt[i][strlen(rt[i]) - 1] = '\0';
        rt[i + 1] = NULL;
    }
    if (copy != NULL)
        free(copy);
    return (rt);
}

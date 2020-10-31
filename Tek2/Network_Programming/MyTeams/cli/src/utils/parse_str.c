/*
** EPITECH PROJECT, 2020
** myteams_cli
** File description:
** parse_str.c
*/

#include <stdlib.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int count_c(const char* str, char c)
{
    int rt = 0;
    for (int i = 0; str[i]; i++)
        if (str[i] == c)
            rt++;
    return (rt);
}

char** parse_str(char* str, char c)
{
    (void)(c);
    char** rt = malloc(sizeof(char *) * (count_c(str, ' ') + 2));
    char* copy = strdup(str);
    char* tmp = strtok(copy, " ");

    for (int i = 0; tmp != NULL; i++, tmp = strtok(NULL, " ")) {
        rt[i] = strdup(tmp);
        if (rt[i][strlen(rt[i]) - 1] == '\n')
            rt[i][strlen(rt[i]) - 1] = 0;
        rt[i + 1] = NULL;
    }
    free(copy);
    return (rt);
}
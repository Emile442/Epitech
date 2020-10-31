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

char** parse_str(char* str)
{
    char** rt = malloc(count_c(str, ' ') * sizeof(char*) + 1);
    char* copy = strdup(str);
    char* tmp = strtok(copy, " ");
    for (int i = 0; tmp != NULL; i++, tmp = strtok(NULL, " ")) {
        rt[i] = strdup(tmp);
        rt[i + 1] = NULL;
    }
    free(copy);
    return (rt);
}
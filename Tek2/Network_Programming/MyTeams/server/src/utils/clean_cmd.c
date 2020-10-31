/*
** EPITECH PROJECT, 2020
** myteams_server
** File description:
** clean_cmd.c
*/

#include "my_teams.h"

char* clean_cmd(const char* cmd)
{
    char* str = malloc(strlen(cmd) * sizeof(char));
    char* copy = strdup(cmd);

    for (int i = 0, j = 0; copy[i]; i++) {
        if (copy[i] == '"')
            continue;
        str[j] = copy[i];
        j++;
    }
    return (str);
}

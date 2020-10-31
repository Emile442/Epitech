/*
** EPITECH PROJECT, 2020
** server
** File description:
** cmd_parsing
*/

#include "my_teams.h"

// First: "send" "TATA" "TOTOT"
// send "TATATA" "TOTOTOT"

int params_count(char** commands)
{
    int i = 0;

    for (; commands[i]; i++);
    return (i);
}

static char **malloc_parameters(const int length)
{
    char **parameters = calloc(length + 1, sizeof(char *));

    for (int i = 0; i < length; i++) {
        parameters[i] = calloc(length + 1, sizeof(char));
    }
    return (parameters);
}

static void get_command(char *command, const char *str)
{
    for (int i = 0; str[i]; i++) {
        if (str[i] == ' ' || str[i] == '\r' || str[i] == '\n')
            break;
        command[i] = str[i];
    }
}

char **command_parsing(const char *str)
{
    char **parameters = malloc_parameters(strlen(str));
    int count_params = 0;

    get_command(parameters[count_params++], str);
    for (int i = 0, in_quotes = false, count_chars = 0; str[i]; i++) {
        if (str[i] != '"' && !in_quotes)
            continue;
        if (str[i] == '"' && !in_quotes) {
            in_quotes = true;
            continue;
        }
        if (str[i] == '"' && in_quotes) {
            count_chars = 0;
            count_params++;
            in_quotes = false;
            continue;
        }
        parameters[count_params][count_chars++] = str[i];
    }
    parameters[count_params] = NULL;
    return (parameters);
}

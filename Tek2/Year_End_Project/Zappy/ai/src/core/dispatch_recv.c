/*
** EPITECH PROJECT, 2020
** zappy
** File description:
** Zappy Disptach server recive
*/

#include "zappy_ai.h"

const fct_tab_t cmd_lists[] = {
    {"WELCOME", cmd_register},
    {"death", cmd_death},
    {NULL, NULL}
};

void free_cmd(char** parse_cmd)
{
    for (int i = 0; parse_cmd[i] != NULL; i++)
        free(parse_cmd[i]);
    if (parse_cmd != NULL)
        free(parse_cmd);
}

void special_command(zappy_t* zappy, char** command)
{
    if (arraylen(command) == 2)
        if (str_is_int(command[0]) && str_is_int(command[1])) {
            zappy->state = 2;
            zappy->height = atoi(command[0]);
            zappy->width = atoi(command[1]);
        }

}

const char *retrieve_look(const char *str)
{
    if (str[0] == '[') {
        if (check_alphanum(str) == false)
            return (NULL);
        else
            return (str);
    }
    return (NULL);
}

void zappy_disptach_recv(zappy_t* zappy, const char* cmd)
{
    char** parse_cmd = parse_str(cmd);
    bool cmd_found = false;

    for (int i = 0; parse_cmd[i]; i++) {
        printf("[%s]\n", parse_cmd[i]);
    }
    for (int i = 0; cmd_lists[i].str && !cmd_found; i++) {
        if (strcmp(cmd_lists[i].str, parse_cmd[0]) == 0) {
            cmd_found = true;
            cmd_lists[i].fct(zappy, parse_cmd);
        }
    }
    retrieve_look(cmd);
    special_command(zappy, parse_cmd);
    free_cmd(parse_cmd);
}

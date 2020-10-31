/*
** EPITECH PROJECT, 2020
** myteams_server
** File description:
** create.c
*/

#include "my_teams.h"

const fct_tab_t fct_create[] = {
    {"teams", command_teams_create},
    {NULL, NULL}
};

void command_disptach_create(my_teams_t * teams, client_t* client, \
char** command)
{
    bool cmd_found = false;

    if (params_count(command) < 3)
        return (send_to(client->socket, rfc_str(404, NOT_FOUND)));
    for (int i = 0; fct_create[i].str && !cmd_found; i++) {
        if (strcmp(fct_create[i].str, command[1]) == 0) {
            cmd_found = true;
            fct_create[i].fct(teams, client, command);
        }
    }
    if (!cmd_found)
        send_to(client->socket, rfc_str(404, NOT_FOUND));
}

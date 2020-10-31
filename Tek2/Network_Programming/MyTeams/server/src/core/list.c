/*
** EPITECH PROJECT, 2020
** myteams_server
** File description:
** list.c
*/

#include "my_teams.h"

const fct_tab_t fct_list[] = {
    {"teams", command_teams_list},
    {NULL, NULL}
};

void command_disptach_list(my_teams_t * teams, client_t* client, char** command)
{
    bool cmd_found = false;

    if (params_count(command) < 2)
        return (send_to(client->socket, rfc_str(404, NOT_FOUND)));
    for (int i = 0; fct_list[i].str && !cmd_found; i++) {
        if (strcmp(fct_list[i].str, command[1]) == 0) {
            cmd_found = true;
            fct_list[i].fct(teams, client, command);
        }
    }
    if (!cmd_found)
        send_to(client->socket, rfc_str(404, NOT_FOUND));
}
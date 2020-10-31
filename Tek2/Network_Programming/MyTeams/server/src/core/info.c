/*
** EPITECH PROJECT, 2020
** myteams_server
** File description:
** info.c
*/

#include "my_teams.h"

const fct_tab_t fct_info[] = {
    {"users", command_user_info},
    {"teams", command_teams_info},
    {NULL, NULL}
};

void command_disptach_info(my_teams_t * teams, client_t* client, char** command)
{
    bool cmd_found = false;

    if (params_count(command) == 1)
        return (fct_info[0].fct(teams, client, command));
    for (int i = 0; fct_info[i].str && !cmd_found; i++) {
        if (strcmp(fct_info[i].str, command[1]) == 0) {
            cmd_found = true;
            fct_info[i].fct(teams, client, command);
        }
    }
    if (!cmd_found)
        send_to(client->socket, rfc_str(404, NOT_FOUND));
}
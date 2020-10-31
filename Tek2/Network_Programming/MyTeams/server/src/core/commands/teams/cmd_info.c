/*
** EPITECH PROJECT, 2020
** myteams_server
** File description:
** cmd_info.c
*/

#include "my_teams.h"

static bool cmd_has_error(client_t* client, char** command)
{
    (void) command;
    if (!is_connected(client)) {
        send_to(client->socket, rfc_str(103, NOT_LOGGED));
        return (true);
    }
    if (params_count(command) != 3) {
        send_to(client->socket, rfc_str(404, NOT_FOUND));
        return (true);
    }
    return (false);
}

void command_teams_info(my_teams_t * teams, client_t* client, char** command)
{
    teams_t* team;

    if (cmd_has_error(client, command))
        return;
    team = teams_get_by_uuid(teams->teams, command[2]);
    if (team == NULL)
        return (send_to(client->socket, rfc_str(154, TEAMS_NOT_FOUND)));
    send_to(client->socket, rfc_str(155, teams_str(team)));
}
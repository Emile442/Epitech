/*
** EPITECH PROJECT, 2020
** myteams_server
** File description:
** cmd_create.c
*/

#include "my_teams.h"

static bool cmd_has_error(client_t* client, char** command)
{
    if (!is_connected(client)) {
        send_to(client->socket, rfc_str(103, NOT_LOGGED));
        return (true);
    }
    if (params_count(command) != 4)
        return (true);
    if (strlen(command[1]) > MAX_NAME_LENGTH) {
        send_to(client->socket, rfc_str(150, NAME_TOO_LONG));
        return (true);
    }
    if (strlen(command[2]) > MAX_DESCRIPTION_LENGTH) {
        send_to(client->socket, rfc_str(151, DESC_TOO_LONG));
        return (true);
    }
    return (false);
}

void command_teams_create(my_teams_t * teams, client_t* client, char** command)
{
    teams_t* team;

    if (cmd_has_error(client, command))
        return;
    team = teams_create(command[2], command[3]);
    teams_push(&teams->teams, team);
    server_event_team_created(team->uuid, team->name, client->uuid);
    send_to(client->socket, rfc_str(152, teams_str(team)));
}
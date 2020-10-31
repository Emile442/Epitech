/*
** EPITECH PROJECT, 2020
** myteams_server
** File description:
** cmd_subscribe.c
*/

#include "my_teams.h"

static bool cmd_has_error(client_t* client, char** command)
{
    if (!is_connected(client)) {
        send_to(client->socket, rfc_str(103, NOT_LOGGED));
        return (true);
    }
    if (params_count(command) != 2)
        return (true);
    return (false);
}

void command_teams_unsubscribe(my_teams_t * teams, client_t* client, \
char** command)
{
    teams_t* team;

    if (cmd_has_error(client, command))
        return;
    team = teams_get_by_uuid(teams->teams, command[1]);
    if (team == NULL)
        return (send_to(client->socket, rfc_str(154, TEAMS_NOT_FOUND)));
    if (user_get_by_uuid(team->subscribers, client->uuid) == NULL)
        return (send_to(client->socket, \
        rfc_str(156, TEAMS_USER_SUB_NOT_FOUND)));
    user_remove_by_uuid(&team->subscribers, client->uuid);
    server_event_user_leave_a_team(team->uuid, client->uuid);
    send_to(client->socket, rfc_str(158, teams_str(team)));
}

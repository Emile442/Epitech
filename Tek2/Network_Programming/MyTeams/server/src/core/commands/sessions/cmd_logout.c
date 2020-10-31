/*
** EPITECH PROJECT, 2020
** myteams_server
** File description:
** logout.c
*/

#include "my_teams.h"

static bool cmd_has_error(client_t* client, char** command)
{
    if (!is_connected(client)) {
        send_to(client->socket, rfc_str(103, NOT_LOGGED));
        return (true);
    }
    if (params_count(command) != 1)
        return (true);
    return (false);
}

void command_logout(my_teams_t * teams, client_t* client, char** command)
{
    (void) command;
    if (cmd_has_error(client, command))
        return;
    user_remove_by_uuid(&teams->sessions.connected, client->uuid);
    send_to(client->socket, rfc_str(104, "Logout"));
    server_event_user_logged_out(client->uuid);
    free(client->uuid);
    client->uuid = NULL;

    for (user_t* tmp = teams->sessions.connected; tmp; tmp = tmp->next)
        printf("name: %s\n", tmp->username);
}
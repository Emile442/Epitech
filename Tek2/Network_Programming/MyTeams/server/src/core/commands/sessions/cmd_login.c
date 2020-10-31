/*
** EPITECH PROJECT, 2020
** myteams_server
** File description:
** login.c
*/

#include "my_teams.h"

static bool cmd_has_error(client_t* client, char** command)
{
    if (is_connected(client)) {
        send_to(client->socket, rfc_str(102, ALREADY_LOGGED));
        return (true);
    }
    if (params_count(command) != 2)
        return (true);
    if (strlen(command[1]) > MAX_NAME_LENGTH) {
        send_to(client->socket, rfc_str(109, NAME_TOO_LONG));
        return (true);
    }
    return (false);
}

void command_login(my_teams_t * teams, client_t* client, char** command)
{
    user_t* user;

    if (cmd_has_error(client, command) || !strlen(command[1]))
        return;
    user = user_found_by_name(teams->sessions.all, command[1]);
    if (user) {
        users_push(&teams->sessions.connected, user);
    } else {
        user = user_create(command[1], client->socket);
        users_push(&teams->sessions.all, user_copy(user));
        users_push(&teams->sessions.connected, user);
        server_event_user_created(user->uuid, user->username);
    }
    server_event_user_logged_in(user->uuid);
    client->uuid = strdup(user->uuid);
    send_to(client->socket, rfc_str(101, get_user_str(user, 1)));
}
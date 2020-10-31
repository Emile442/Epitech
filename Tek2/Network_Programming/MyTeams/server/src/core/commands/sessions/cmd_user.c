/*
** EPITECH PROJECT, 2020
** myteams_server
** File description:
** cmd_user.c
*/

#include "my_teams.h"

void command_user(my_teams_t * teams, client_t* client, char** command)
{
    char* uuid = command[1];
    user_t* user = user_get_by_uuid(teams->sessions.all, uuid);
    int connected = 0;

    if (!is_connected(client))
        return;
    if (user == NULL) {
        send_to(client->socket, rfc_str(107, USER_NOT_FOUND));
        return;
    }
    connected = user_found_by_name(teams->sessions.connected, \
    user->username) ? 1 : 0;
    send_to(client->socket, rfc_str(106, get_user_str(user, connected)));
}

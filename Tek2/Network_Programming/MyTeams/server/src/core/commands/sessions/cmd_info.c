/*
** EPITECH PROJECT, 2020
** myteams_server
** File description:
** cmd_info.c
*/

#include "my_teams.h"

void command_user_info(my_teams_t * teams, client_t* client, char** command)
{
    user_t* user;

    (void)command;
    if (client->uuid == NULL) {
        send_to(client->socket, rfc_str(103, NOT_LOGGED));
        return;
    }
    user = user_get_by_uuid(teams->sessions.all, client->uuid);
    if (user == NULL) {
        send_to(client->socket, rfc_str(107, USER_NOT_FOUND));
        return;
    }
    send_to(client->socket, rfc_str(106, get_user_str(user, 1)));
}
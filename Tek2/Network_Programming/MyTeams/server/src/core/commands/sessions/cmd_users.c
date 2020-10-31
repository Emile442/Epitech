/*
** EPITECH PROJECT, 2020
** myteams_server
** File description:
** cmd_users.c
*/

#include "my_teams.h"

void command_users(my_teams_t * teams, client_t* client, char** command)
{
    char* str;
    int length = 0;
    int count = 0;
    (void) command;

    if (is_connected(client))
        return;
    if (teams->sessions.all == NULL)
        return (send_to(client->socket, rfc_str(105, "")));
    for (user_t* tmp = teams->sessions.all; tmp; tmp = tmp->next, count++)
        length += strlen(get_user_str(tmp, 0));
    str = calloc(length + count + 1, sizeof(char));
    for (user_t* tmp = teams->sessions.all; tmp; tmp = tmp->next) {
        strcat(str, get_user_str(tmp, user_found_by_name(\
        teams->sessions.connected, tmp->username) ? 1 : 0));
        if (tmp->next)
            strcat(str, "#");
    }
    send_to(client->socket, rfc_str(105, str));
}

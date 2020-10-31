/*
** EPITECH PROJECT, 2020
** myteams_server
** File description:
** cmd_messages.c
*/

#include "my_teams.h"

static void send_all_messages(message_t **list, int to)
{
    int len = 1;
    char* rt;

    for (message_t *tmp = *list; tmp; tmp = tmp->next)
        len += strlen(messages_str(tmp->from, tmp->created_at, tmp->body)) + 1;
    rt = calloc(len, sizeof(char));
    for (message_t *tmp = *list; tmp; tmp = tmp->next) {
        strcat(rt, messages_str(tmp->from, tmp->created_at, tmp->body));
        if (tmp->next != NULL)
            strcat(rt, "#");
    }
    send_to(to, rfc_str(125, rt));
    free(rt);
}

static bool cmd_has_error(my_teams_t* teams, client_t* client, char** command)
{
    if (!is_connected(client)) {
        send_to(client->socket, rfc_str(103, NOT_LOGGED));
        return (true);
    }
    if (params_count(command) != 2)
        return (true);
    if (user_found_by_uuid(teams->sessions.all, command[1]) == NULL) {
        send_to(client->socket, rfc_str(107, USER_NOT_FOUND));
        return true;
    }
    return (false);
}

void command_messages(my_teams_t * teams, client_t* client, char** command)
{
    conversation_t * conv;

    if (cmd_has_error(teams, client, command))
        return;
    conv = conv_get_by_uuid(teams->conversations, client->uuid, \
    command[1]);
    if (conv == NULL || conv->messages == NULL) {
        send_to(client->socket, rfc_str(124, "No messages"));
        return;
    }
    send_all_messages(&conv->messages, client->socket);
}

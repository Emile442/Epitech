/*
** EPITECH PROJECT, 2020
** myteams_server
** File description:
** send.c
*/

#include "my_teams.h"

static bool cmd_has_error(my_teams_t* teams, client_t* client, char** command)
{
    if (!is_connected(client)) {
        send_to(client->socket, rfc_str(103, NOT_LOGGED));
        return (true);
    }
    if (params_count(command) != 3)
        return (true);
    if (user_found_by_uuid(teams->sessions.all, command[1]) == NULL) {
        send_to(client->socket, rfc_str(107, USER_NOT_FOUND));
        return true;
    }
    if (strlen(command[2]) > MAX_BODY_LENGTH) {
        send_to(client->socket, rfc_str(122, BODY_TOO_LONG));
        return (true);
    }
    return (false);
}

void cmd_msg_2(user_t* dest, client_t* client, message_t* msg)
{
    if (dest != NULL)
        send_to(dest->socket, rfc_str(120, \
        messages_str(msg->from, msg->created_at, msg->body)));
    send_to(client->socket, rfc_str(121, \
    messages_str(msg->from, msg->created_at, msg->body)));
}

void command_messages_send(my_teams_t * teams, client_t* client, char** command)
{
    char* uuid = command[1];
    conversation_t* conv;
    message_t* msg;
    user_t* dest = user_found_by_uuid(teams->sessions.connected, uuid);

    if (cmd_has_error(teams, client, command))
        return;
    msg = messages_create(client->uuid, command[2]);
    if (conv_get_by_uuid(teams->conversations, client->uuid, uuid)) {
        conv = conv_get_by_uuid(teams->conversations, client->uuid, uuid);
        printf("Alredy exist\n");
    } else {
        conv = conversations_create(client->uuid, uuid);
        conversations_push(&teams->conversations, conv);
    }
    messages_push(&conv->messages, msg);
    server_event_private_message_sended(msg->from, dest->uuid, msg->body);
    cmd_msg_2(dest, client, msg);
    free(uuid);
}

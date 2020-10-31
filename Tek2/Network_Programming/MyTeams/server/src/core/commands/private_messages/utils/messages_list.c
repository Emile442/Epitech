/*
** EPITECH PROJECT, 2020
** myteams_server
** File description:
** messages_list.c
*/

#include "my_teams.h"

void messages_print(message_t **list)
{
    message_t *tmp = *list;

    for (; tmp; tmp = tmp->next)
        printf("%s: %s\n", tmp->from, tmp->body);
}

void conversations_print(conversation_t **list)
{
    conversation_t *tmp = *list;

    for (; tmp; tmp = tmp->next)
        printf("CONV === %s: %s\n", tmp->uuid1, tmp->uuid2);
}

void messages_push(message_t ** list, message_t* msg)
{
    msg->next = (*list);
    (*list) = msg;
}

message_t* messages_create(const char* from, const char* body)
{
    message_t* msg = malloc(sizeof(message_t));

    msg->from = strdup(from);
    msg->body = strdup(body);
    msg->created_at = time(0);
    return (msg);
}

char* messages_str(const char* uuid, time_t created_at, const char* body)
{
    int len = strlen(uuid) + strlen(body) + 3;
    char* rt;
    char* nbrStr = calloc(50, sizeof(char));

    sprintf(nbrStr, "%ld", created_at);
    len += strlen(nbrStr);
    rt = calloc(len, sizeof(char));
    strcat(rt, uuid);
    strcat(rt, " ");
    strcat(rt, nbrStr);
    strcat(rt, " ");
    strcat(rt, body);
    free(nbrStr);
    return (rt);
}

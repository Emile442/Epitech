/*
** EPITECH PROJECT, 2020
** myteams_server
** File description:
** conversations_list.c
*/

#include "my_teams.h"

void conversations_push(conversation_t** list, conversation_t* conv)
{
    conv->next = (*list);
    (*list) = conv;
}

conversation_t* conversations_create(const char* uuid1, const char* uuid2)
{
    conversation_t* conv = malloc(sizeof(conversation_t));

    conv->uuid1 = strdup(uuid1);
    conv->uuid2 = strdup(uuid2);
    return (conv);
}

conversation_t* conv_get_by_uuid(conversation_t *list, \
const char* uuid1, const char* uuid2)
{
    conversation_t* tmp = list;

    if (list == NULL)
        return (NULL);
    for (int i = 0; tmp; tmp = tmp->next, i++) {
        if (strcmp(tmp->uuid1, uuid1) == 0 && strcmp(tmp->uuid2, uuid2) == 0)
            return (tmp);
        if (strcmp(tmp->uuid1, uuid2) == 0 && strcmp(tmp->uuid2, uuid1) == 0)
            return (tmp);
    }
    return (NULL);
}

conversation_t* conversations_found_by_uuid(conversation_t *list, \
const char* uuid1, const char* uuid2)
{
    conversation_t* tmp = list;

    if (list == NULL)
        return (NULL);
    for (; tmp; tmp = tmp->next) {
        if (strcmp(tmp->uuid1, uuid1) == 0 && strcmp(tmp->uuid2, uuid2) == 0)
            return (tmp);
        if (strcmp(tmp->uuid1, uuid2) == 0 && strcmp(tmp->uuid2, uuid1) == 0)
            return (tmp);
    }
    return (NULL);
}

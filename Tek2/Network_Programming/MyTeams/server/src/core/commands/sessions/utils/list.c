/*
** EPITECH PROJECT, 2020
** myteams_server
** File description:
** list.c
*/

#include "my_teams.h"

void users_push(user_t** list, user_t* user)
{
    user->next = (*list);
    (*list) = user;
}

void users_pull(user_t **list)
{
    if (*list != NULL)
        (*list) = (*list)->next;
}

int user_get_pos_by_uuid(user_t *list, const char* uuid)
{
    user_t* tmp = list;

    if (list == NULL)
        return (-1);
    for (int i = 0; tmp; tmp = tmp->next, i++)
        if (strcmp(tmp->uuid, uuid) == 0)
            return (i);
    return (-1);
}

user_t* user_get_by_uuid(user_t *list, const char* uuid)
{
    user_t* tmp = list;

    if (list == NULL)
        return (NULL);
    for (int i = 0; tmp; tmp = tmp->next, i++)
        if (strcmp(tmp->uuid, uuid) == 0)
            return (tmp);
    return (NULL);
}

void user_remove_by_uuid(user_t **list, const char* uuid)
{
    int pos = user_get_pos_by_uuid(*list, uuid);
    user_t* tmp = *list;

    if (*list == NULL || pos == -1)
        return;
    if (pos == 0) {
        *list = tmp->next;
        free(tmp);
        return;
    }
    for (int i=0; tmp != NULL && i < pos - 1; i++)
        tmp = tmp->next;
    if (tmp == NULL || tmp->next == NULL)
        return;
    user_t* next = tmp->next->next;
    free(tmp->next);
    tmp->next = next;
}

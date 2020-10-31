/*
** EPITECH PROJECT, 2020
** myteams_server
** File description:
** user.c
*/

#include "my_teams.h"

char* get_user_str(user_t* user, int status)
{
    char* str = calloc(strlen(user->username) + strlen(user->uuid) + 2 + 2, \
    sizeof(char));

    strcat(str, user->username);
    strcat(str, ":");
    strcat(str, user->uuid);
    strcat(str, ":");
    if (status == 1)
        strcat(str, "1");
    else
        strcat(str, "0");
    return (str);
}

user_t* user_create(const char* username, int socket)
{
    user_t* user = malloc(sizeof(user_t));

    user->uuid = generate_uuid();
    user->username = strdup(username);
    user->socket = socket;
    return (user);
}

user_t* user_found_by_name(user_t *list, const char* username)
{
    user_t* tmp = list;

    if (list == NULL)
        return (NULL);
    for (; tmp; tmp = tmp->next)
        if (strcmp(tmp->username, username) == 0)
            return (tmp);
    return (NULL);
}

user_t* user_found_by_uuid(user_t *list, const char* uuid)
{
    user_t* tmp = list;

    if (list == NULL)
        return (NULL);
    for (; tmp; tmp = tmp->next)
        if (strcmp(tmp->uuid, uuid) == 0)
            return (tmp);
    return (NULL);
}

user_t* user_copy(user_t* user)
{
    user_t* copy = malloc(sizeof(user_t));

    copy->username = strdup(user->username);
    copy->uuid = strdup(user->uuid);
    copy->socket = user->socket;
    return (copy);
}

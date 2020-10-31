/*
** EPITECH PROJECT, 2020
** zappy
** File description:
** Clients Utils
*/

#include "zappy_server.h"
#include "network.h"

void client_push(client_t **list, int socket)
{
    client_t* new_val = malloc(sizeof(client_t));

    if (new_val == NULL)
        exit(84);
    new_val->socket = socket;
    new_val->uuid = generate_uuid();
    new_val->next = (*list);
    new_val->player = NULL;
    (*list) = new_val;
}

client_t* client_found_by_uuid(client_t *list, const char* uuid)
{
    client_t* tmp = list;

    if (list == NULL)
        return (NULL);
    for (; tmp; tmp = tmp->next)
        if (strcmp(tmp->uuid, uuid) == 0)
            return (tmp);
    return (NULL);
}

int client_get_pos(client_t *list, client_t *query)
{
    client_t* tmp = list;

    if (list == NULL)
        return (-1);
    for (int i = 0; tmp; tmp = tmp->next, i++)
        if (tmp == query)
            return (i);
    return (-1);
}

void client_remove(client_t **list, client_t *query)
{
    int pos = client_get_pos(*list, query);
    client_t* tmp = *list;

    if (*list == NULL || pos == -1)
        return;
    if (pos == 0) {
        *list = tmp->next;
        return;
    }
    for (int i=0; tmp != NULL && i < pos - 1; i++)
        tmp = tmp->next;
    if (tmp == NULL || tmp->next == NULL)
        return;
    client_t* next = tmp->next->next;
    tmp->next = next;
}

int client_size(client_t* clients)
{
    int size = 0;

    for (client_t *cus = clients; cus; cus = cus->next)
        size++;
    return (size);
}

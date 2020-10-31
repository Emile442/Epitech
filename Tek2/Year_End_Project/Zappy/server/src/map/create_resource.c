/*
** EPITECH PROJECT, 2023
** zappy
** File description:
** create_resource.c
*/

#include "zappy_server.h"

resource_t *create_resource(enum RESOURCE_TYPE resource_type, int amount)
{
    resource_t *res = malloc(sizeof(resource_t));

    if (res == NULL) {
        return (NULL);
    }
    res->amount = amount;
    res->resource_type = resource_type;
    res->resource_name = get_resource_name(resource_type);
    res->next = NULL;
    return (res);
}

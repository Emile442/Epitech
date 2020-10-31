/*
** EPITECH PROJECT, 2020
** zappy
** File description:
** cmd_take_object.c
*/

#include "zappy_server.h"

resource_t *find_node(map_tile_t *current_tile, char *object)
{
    resource_t* rs = current_tile->entities->resources;
    for (resource_t *tile = rs; tile; tile = tile->next)
        if (strcmp(tile->resource_name, object) == 0)
            return (tile);
    return (NULL);
}

void cmd_take_object(zappy_t *zappy, client_t *client, char **command)
{
    resource_t *res = find_node(client->player->current_tile, command[1]);
    resource_t *inventory = client->player->resources;

    (void)zappy;
    wait_time(zappy, 7);
    if (res == NULL)
        return;
    res->prev->next = res->next;
    res->next->prev = res->prev;
    for (; inventory; inventory = inventory->next);
    inventory = res;
}

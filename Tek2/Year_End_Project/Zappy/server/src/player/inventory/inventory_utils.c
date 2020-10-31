/*
** EPITECH PROJECT, 2023
** zappy
** File description:
** inventory_utils.c
*/

#include "player.h"

resource_t *get_resource(player_t *player, enum RESOURCE_TYPE type)
{
    resource_t *item = NULL;

    if (player == NULL)
        return (NULL);
    item = player->resources;
    if (item == NULL)
        return (NULL);
    while (item != NULL) {
        if (item->resource_type == type)
            return (item);
        item = item->next;
    }
    return (NULL);
}

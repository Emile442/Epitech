/*
** EPITECH PROJECT, 2023
** zappy
** File description:
** utils_map.c
*/

#include "zappy_server.h"

char *res_names[8] = {"food", "linemate", "deraumere",
    "sibur", "mendiane", "phiras", "thystame", ""};

map_tile_t *random_spawn_position(zappy_t *zappy)
{
    map_tile_t *first = zappy->maps->first_slot;

    return (first->right->left->down->right->left);
}

char* get_resource_name(enum RESOURCE_TYPE type)
{
    return (res_names[type]);
}

int tile_inventory_str_len(map_tile_t* tile)
{
    int players_size;
    int len = 0;
    tile_entities_t* entity = tile->entities;

    if (tile->entities == NULL)
        return (len);
    players_size = player_size(entity->players);
    if (players_size)
        len += (6 * players_size) + players_size;
    if (entity->eggs)
        len += 1 + 3;
    if (entity->resources != NULL) {
        for (resource_t* tmp = entity->resources; tmp; tmp = tmp->next) {
            len += get_resource_name(tmp->resource_type) == NULL ? 0 :\
            1 + strlen(get_resource_name(tmp->resource_type));
        }
    }
    return (len);
}

char* tile_inventory_str(map_tile_t* tile)
{
    char* rt;
    int len = tile_inventory_str_len(tile);
    tile_entities_t* entity = tile->entities;

    rt = calloc(len, sizeof(char));
    if (len == 0)
        return ("");
    for (player_t* pl = entity->players; pl; pl = pl->next) {
        strcat(rt, "player");
        if (pl->next)
            strcat(rt, " ");
    }
    if (entity->eggs) {
        strcat(rt, "egg");
    }
    for (resource_t* pl = entity->resources; pl; pl = pl->next) {
        strcat(rt, get_resource_name(pl->resource_type));
        if (pl->next)
            strcat(rt, " ");
    }
    return (rt);
}

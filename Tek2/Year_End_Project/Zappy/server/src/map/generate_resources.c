/*
** EPITECH PROJECT, 2020
** zappy
** File description:
** generate_ressources.c
*/

#include "zappy_server.h"

enum RESOURCE_TYPE get_random_type(int value)
{
    int j = 0;

    for (enum RESOURCE_TYPE type = FOOD; type != NONE && j <= value; type++) {
        if (j == value) {
            return (type);
        }
        j++;
    }
    return (NONE);
}

void add_tile_resource(map_tile_t *current_tile)
{
    int value = rand() % 8;

    current_tile->entities->resources = create_resource(\
    get_random_type(value), 2);
}

void loop_tile(map_t *map)
{
    map_tile_t *current_tile = map->first_slot;

    for (int i = 0; i < map->height; i++) {
        for (int j = 0; j < map->width; j++) {
            add_tile_resource(current_tile);
            current_tile = current_tile->right;
        }
        current_tile = current_tile->down;
    }
}

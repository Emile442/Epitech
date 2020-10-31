/*
** EPITECH PROJECT, 2023
** zappy
** File description:
** free_map.c
*/

#include "zappy_server.h"

void free_line(map_tile_t *head)
{
    map_tile_t *cur = head->right;

    if (cur == NULL)
        return;
    while (cur != head) {
        cur = cur->right;
        if (cur == NULL)
            return;
        if (cur->left == NULL)
            return;
        free(cur->left);
    }
}

void free_head(map_tile_t *head)
{
    map_tile_t *cur = head->up;

    if (cur == NULL)
        return;
    while (cur != head) {
        cur = cur->up;
        if (cur == NULL)
            return;
        if (cur->down == NULL)
            return;
        free(cur->down);
    }
    free(cur);
}

void free_map(map_t *map)
{
    map_tile_t *cur = map->first_slot;

    cur = cur->up;
    if (cur == NULL)
        return;
    while (cur != map->first_slot) {
        free_line(cur);
        cur = cur->up;
    }
    free_line(map->first_slot);
    free_head(map->first_slot);
    free(map);
}
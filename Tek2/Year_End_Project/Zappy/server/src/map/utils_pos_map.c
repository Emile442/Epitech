/*
** EPITECH PROJECT, 2020
** zappy
** File description:
** utils_pos_map
*/

#include "zappy_server.h"

int get_tile_direction_bis(int x, int y)
{
    if (x == 1 && y == -1)
        return (6);
    if (x == 1 && y == 0)
        return (7);
    if (x == 1 && y == 1)
        return (8);
    return (0);
}

int get_tile_direction(map_tile_t* tile_a, map_tile_t* tile_b)
{
    int x = (tile_a->pos_x > tile_b->pos_x) ? -1 : 0;
    int y = (tile_a->pos_y > tile_b->pos_y) ? -1 : 0;

    x = (tile_a->pos_x < tile_b->pos_x) ? 1 : x;
    y = (tile_a->pos_y < tile_b->pos_y) ? 1 : y;
    if (x == 0 && y == 1)
        return (1);
    if (x == -1 && y == 1)
        return (2);
    if (x == -1 && y == 0)
        return (3);
    if (x == -1 && y == -1)
        return (4);
    if (x == 0 && y == -1)
        return (5);
    return (get_tile_direction_bis(x, y));
}

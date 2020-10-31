/*
** EPITECH PROJECT, 2023
** zappy
** File description:
** link_map.c
*/

#include "zappy_server.h"

int link_tiles(map_tile_t *tile1, map_tile_t *tile2, int direction)
{
    if (tile1 == NULL || tile2 == NULL)
        return (LINK_FAILED);
    if (direction == UP) {
        tile1->up = tile2;
        tile2->down = tile1;
    } else if (direction == LEFT) {
        tile1->left = tile2;
        tile2->right = tile1;
    } else if (direction == DOWN) {
        tile1->down = tile2;
        tile2->up = tile1;
    } else if (direction == RIGHT) {
        tile1->right = tile2;
        tile2->left = tile1;
    } else
        return (LINK_FAILED);
    return (LINK_OK);
}

int link_lines(map_tile_t *head1, map_tile_t *head2, int size)
{
    map_tile_t *cur1 = head1;
    map_tile_t *cur2 = head2;

    if (head1 == NULL || head2 == NULL)
        return (LINK_FAILED);
    for (int i = 0; i < size; i++) {
        link_tiles(cur1, cur2, DOWN);
        cur1 = cur1->right;
        cur2 = cur2->right;
    }
    return (LINK_OK);
}
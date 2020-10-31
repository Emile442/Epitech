/*
** EPITECH PROJECT, 2023
** zappy
** File description:
** init_map.c
*/

#include "zappy_server.h"

map_t *alloc_map(int width, int height)
{
    map_t *game_map = malloc(sizeof(map_t));

    if (game_map == NULL)
        return (NULL);
    game_map->width = width;
    game_map->height = height;
    game_map->first_slot = NULL;
    return (game_map);
}

map_tile_t *alloc_tile(int x, int y)
{
    map_tile_t *map_tile = malloc(sizeof(map_tile_t));
    tile_entities_t *entity = calloc(1, sizeof(tile_entities_t));

    if (map_tile == NULL)
        return (NULL);
    if (entity == NULL)
        return (NULL);
    map_tile->pos_x = x;
    map_tile->pos_y = y;
    map_tile->up = NULL;
    map_tile->left = NULL;
    map_tile->down = NULL;
    map_tile->right = NULL;
    map_tile->entities = entity;
    return (map_tile);
}

map_tile_t *alloc_line(int x, int size)
{
    map_tile_t *head = alloc_tile(x, 0);
    map_tile_t *last_alloc_tile;
    map_tile_t *new_tile;

    if (head == NULL)
        return (NULL);
    last_alloc_tile = head;
    for (int y = 1; y < size; y++) {
        new_tile = alloc_tile(x, y);
        if (link_tiles(last_alloc_tile, new_tile, RIGHT) == LINK_FAILED)
            return (NULL);
        last_alloc_tile = new_tile;
    }
    link_tiles(head, last_alloc_tile, LEFT);
    return (head);
}

map_t *create_map(int width, int height)
{
    map_t *game_map = alloc_map(width, height);
    map_tile_t *last_alloc_line;
    map_tile_t *new_line;

    if (game_map == NULL)
        return (NULL);
    game_map->first_slot = alloc_line(0, width);
    if (game_map->first_slot == NULL)
        return (NULL);
    last_alloc_line = game_map->first_slot;
    for (int i = 1; i < height; i++) {
        new_line = alloc_line(i, width);
        if (link_lines(last_alloc_line, new_line, width) == LINK_FAILED)
            return (NULL);
        last_alloc_line = new_line;
    }
    link_lines(last_alloc_line, game_map->first_slot, width);
    loop_tile(game_map);
    return (game_map);
}

/*
** EPITECH PROJECT, 2018
** maps_info
** File description:
** Maps Info
*/

#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

#include "my.h"
#include "sokoban.h"

int get_map_length(char* const map)
{
    int length = 0;

    for (int i = 0; map[i]; i++)
        if (map[i] == '\n')
            length++;
    if (length == 0)
        exit(EPI_FAILURE);
    return (length - 1);
}

int get_map_width(char* const map)
{
    int length = 0;

    for (int i = 0; map[i] != '\n'; i++) {
        length++;
    }
    if (length == 0)
        exit(EPI_FAILURE);
    return (length);
}

bool can_move(coord_t *coord, map_t *map)
{
    int col_count;
    int row_count = map->row;

    if (coord->x > row_count || coord->x < 0)
        return (false);
    col_count = my_strlen(map->plan[coord->x]);
    if (coord->y >= col_count - 1 || coord->y < 0)
        return (false);
    if (map->plan[coord->x][coord->y] == '#')
        return (false);
    return (true);
}

bool is_box(coord_t *coord, map_t *map)
{
    if (map->plan[coord->x][coord->y] == 'X')
        return (true);
    return (false);
}

bool is_storage(coord_t *coord, map_t *map)
{
    if (map->plan[coord->x][coord->y] == 'O')
        return (true);
    return (false);
}
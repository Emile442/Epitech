/*
** EPITECH PROJECT, 2018
** player
** File description:
** Player
*/

#include <unistd.h>
#include <stdlib.h>

#include "my.h"
#include "sokoban.h"

void static set_player2(coord_t *player, map_t *map, int i, int j)
{
    if (map->plan[i][j] == 'P') {
        player->x = i;
        player->y = j;
        player->c = map->plan[i][j];
    }
}

void set_player(coord_t *player, map_t *map)
{
    for (int i = 0; i <= map->row; i++) {
        for (int j = 0; j < map->col; j++) {
            set_player2(player, map, i, j);
        }
    }
}

void set_last(coord_t *last, coord_t *player)
{
    last->x = player->x;
    last->y = player->y;
    last->c = ' ';
}

void update_last(coord_t *last, coord_t *player, map_t *map)
{
    char c = map->plan[player->x][player->y];

    last->x = player->x;
    last->y = player->y;
    last->c = (c == 'P') ? ' ' : c;
}
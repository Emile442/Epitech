/*
** EPITECH PROJECT, 2018
** game_status
** File description:
** Game status
*/

#include "sokoban.h"
#include <stdio.h>

void static check_loose2(game_t *g, int i, int j)
{
    if (g->map->plan[i][j] == 'X') {
        if ((g->map->plan[i][j - 1] == '#' && g->map->plan[i - 1][j] == '#')
        || (g->map->plan[i][j - 1] == '#' && g->map->plan[i + 1][j] == '#')
        || (g->map->plan[i][j + 1] == '#' && g->map->plan[i - 1][j] == '#')
        || (g->map->plan[i][j + 1]== '#' && g->map->plan[i + 1][j] == '#')){
            g->loose++;
        }
        if (g->map->plan[i][j] == 'X' && g->backup->plan[i][j] == 'O') {
            g->loose--;
        }
    }
}

void check_loose(game_t *game)
{
    for (int i = 0; i <= game->map->row; i++) {
        for (int j = 0; j < game->map->col; j++) {
            check_loose2(game, i, j);
        }
    }
    if (game->loose != game->info->box)
        game->loose = 0;
}

int static check_win2(game_t *game, int i, int j)
{
    if (game->backup->plan[i][j] == 'O' && game->map->plan[i][j] == 'X')
        return (1);
    return (0);
}

void check_win(game_t *game)
{
    int count = 0;

    for (int i = 0; i <= game->map->row; i++) {
        for (int j = 0; j < game->map->col; j++) {
            count += check_win2(game, i, j);
        }
    }
    if (count == game->map->storage) {
        game->win = 1;
    }
}
/*
** EPITECH PROJECT, 2018
** print_move
** File description:
** Display Move
*/

#include <unistd.h>
#include <stdlib.h>
#include <stdbool.h>
#include <sys/stat.h>
#include <ncurses.h>

#include "my.h"
#include "sokoban.h"

void move_box(game_t *game, coord_t *actual, coord_t *new)
{
    game->map->plan[actual->x][actual->y] = ' ';
    game->map->plan[new->x][new->y] = 'X';
}

void move_player(game_t *game, coord_t *new)
{
    game->map->plan[game->player->x][game->player->y] = ' ';
    game->player->x = new->x;
    game->player->y = new->y;
    game->map->plan[game->player->x][game->player->y] = 'P';
}

void move_object(game_t *game, coord_t *new, coord_t *front)
{
    if (can_move(new, game->map)) {
        if (is_box(new, game->map) && can_move(front, game->map)
        && !is_box(front, game->map)) {
            move_box(game, new, front);
            move_player(game, new);
        } else if (!is_box(new, game->map)) {
            move_player(game, new);
        }
    }
    check_storage(game);
    check_loose(game);
    check_win(game);
}
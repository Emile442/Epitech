/*
** EPITECH PROJECT, 2018
** player_move
** File description:
** Player move
*/

#include <unistd.h>
#include <stdlib.h>
#include <stdbool.h>
#include <sys/stat.h>
#include <ncurses.h>

#include "my.h"
#include "sokoban.h"

void up_player(game_t *game)
{
    coord_t *new = malloc(sizeof(coord_t));
    coord_t *front = malloc(sizeof(coord_t));

    new->x = game->player->x - 1;
    new->y = game->player->y;
    front->x = game->player->x - 2;
    front->y = game->player->y;
    move_object(game, new, front);
}

void down_player(game_t *game)
{
    coord_t *new = malloc(sizeof(coord_t));
    coord_t *front = malloc(sizeof(coord_t));
    coord_t *newFront = malloc(sizeof(coord_t));

    new->x = game->player->x + 1;
    new->y = game->player->y;
    front->x = game->player->x + 2;
    front->y = game->player->y;
    move_object(game, new, front);
}

void right_player(game_t *game)
{
    coord_t *new = malloc(sizeof(coord_t));
    coord_t *front = malloc(sizeof(coord_t));

    new->x = game->player->x;
    new->y = game->player->y + 1;
    front->x = game->player->x;
    front->y = game->player->y + 2;
    move_object(game, new, front);
}

void left_player(game_t *game)
{
    coord_t *new = malloc(sizeof(coord_t));
    coord_t *front = malloc(sizeof(coord_t));

    new->x = game->player->x;
    new->y = game->player->y - 1;
    front->x = game->player->x;
    front->y = game->player->y - 2;
    move_object(game, new, front);
}
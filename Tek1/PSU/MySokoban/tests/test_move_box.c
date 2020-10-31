/*
** EPITECH PROJECT, 2018
** test_box
** File description:
** Check box & platyer has been move
*/

#include <criterion/criterion.h>

#include "my.h"
#include "sokoban.h"

Test(move_box, has_been_move)
{
    game_t *game = init_game("test.map");

    down_player(game);
    cr_assert_eq(game->map->plan[3][5], 'X');
    right_player(game);
    cr_assert_eq(game->player->x, 3);
    cr_assert_eq(game->player->y, 5);
    cr_assert_eq(game->map->plan[game->player->x][game->player->y], 'P');
    cr_assert_eq(game->map->plan[3][5], 'P');
    cr_assert_eq(game->map->plan[3][6], 'X');
}
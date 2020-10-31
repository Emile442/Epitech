/*
** EPITECH PROJECT, 2018
** test_move
** File description:
** Check player has been move
*/

#include <criterion/criterion.h>

#include "my.h"
#include "sokoban.h"

Test(up_player, has_been_up)
{
    game_t *game = init_game("test.map");

    up_player(game);
    cr_assert_eq(game->player->x, 1);
    cr_assert_eq(game->player->y, 4);
    cr_assert_eq(game->map->plan[game->player->x][game->player->y], 'P');
}

Test(down_player, has_been_down)
{
    game_t *game = init_game("test.map");

    down_player(game);
    cr_assert_eq(game->player->x, 3);
    cr_assert_eq(game->player->y, 4);
    cr_assert_eq(game->map->plan[game->player->x][game->player->y], 'P');
}

Test(right_player, has_been_right)
{
    game_t *game = init_game("test.map");

    right_player(game);
    cr_assert_eq(game->player->x, 2);
    cr_assert_eq(game->player->y, 5);
    cr_assert_eq(game->map->plan[game->player->x][game->player->y], 'P');
}

Test(left_player, has_been_left)
{
    game_t *game = init_game("test.map");

    left_player(game);
    cr_assert_eq(game->player->x, 2);
    cr_assert_eq(game->player->y, 3);
    cr_assert_eq(game->map->plan[game->player->x][game->player->y], 'P');
}
/*
** EPITECH PROJECT, 2018
** test_move_wall
** File description:
** Check player has been not move
*/

#include <criterion/criterion.h>

#include "my.h"
#include "sokoban.h"

Test(up_player, dont_move_wall)
{
    game_t *game = init_game("test.map");

    up_player(game);
    up_player(game);
    up_player(game);
    up_player(game);
    up_player(game);
    cr_assert_eq(game->player->x, 1);
    cr_assert_eq(game->player->y, 4);
    cr_assert_eq(game->map->plan[game->player->x][game->player->y], 'P');
}
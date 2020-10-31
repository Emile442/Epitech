/*
** EPITECH PROJECT, 2018
** test_map
** File description:
** Check Map
*/

#include <criterion/criterion.h>

#include "my.h"
#include "sokoban.h"

Test(set_player, check_player_position)
{
    game_t *game = init_game("test.map");

    cr_assert_eq(game->player->x, 2);
    cr_assert_eq(game->player->y, 4);
}

Test(set_map, map_info)
{
    game_t *game = init_game("test.map");

    cr_assert_eq(game->map->col, 12);
    cr_assert_eq(game->map->row, 11);
}

Test(set_last, has_been_set_with_player)
{
    game_t *game = init_game("test.map");

    cr_assert_eq(game->last->x, game->player->x);
    cr_assert_eq(game->last->y, game->player->y);
    cr_assert_eq(game->last->c, ' ');
}
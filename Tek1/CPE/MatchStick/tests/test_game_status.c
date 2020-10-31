/*
** EPITECH PROJECT, 2019
** CPE_matchstick_2018
** File description:
** tests/game_status
*/

#include <criterion/criterion.h>

#include "my.h"
#include "matchstick.h"

Test(check_end_game, game_not_end)
{
    char** map = map_generator(4);

    cr_assert_eq(check_end_game(map), false);
    map_remove(map, 1, 1);
    cr_assert_eq(check_end_game(map), false);
    free(map);
}

Test(check_end_game, game_end)
{
    char** map = map_generator(4);

    map_remove(map, 1, 1);
    map_remove(map, 2, 3);
    map_remove(map, 3, 5);
    map_remove(map, 4, 7);
    cr_assert_eq(check_end_game(map), true);
    free(map);
}

/*
** EPITECH PROJECT, 2019
** CPE_matchstick_2018
** File description:
** tests/map_utils
*/

#include <criterion/criterion.h>

#include "my.h"
#include "matchstick.h"

Test(count_line_stick, count_line_match)
{
    char** map = map_generator(4);

    cr_assert_eq(count_line_stick(map[3]), 5);
    free(map);
}

Test(can_select_line, can_select_line)
{
    char** map = map_generator(4);

    cr_assert_eq(can_select_line(map, 2, 4), true);
    cr_assert_eq(can_select_line(map, -1, 4), false);
    cr_assert_eq(can_select_line(map, 0, 4), false);
    cr_assert_eq(can_select_line(map, 100, 4), false);
    cr_assert_eq(can_select_line(map, 7, 4), false);
    map_remove(map, 2, 3);
    cr_assert_eq(can_select_line(map, 2, 4), false);
    free(map);
}

Test(map_can_supr, map_can_supr)
{
    char** map = map_generator(4);

    cr_assert_eq(map_can_supr(map[2], 2, 3), true);
    cr_assert_eq(map_can_supr(map[2], 3, 3), true);
    cr_assert_eq(map_can_supr(map[2], 4, 3), false);
    cr_assert_eq(map_can_supr(map[2], -4, 3), false);
    cr_assert_eq(map_can_supr(map[2], 100, 3), false);
    cr_assert_eq(map_can_supr(map[1], 2, 3), false);
    free(map);
}

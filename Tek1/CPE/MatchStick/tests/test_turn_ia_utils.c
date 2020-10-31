/*
** EPITECH PROJECT, 2019
** CPE_matchstick_2018
** File description:
** tests/turn_ia_utils
*/

#include <criterion/criterion.h>

#include "my.h"
#include "matchstick.h"

Test(is_pair, nbr_pair)
{
    int nb = 2;

    cr_assert_eq(is_pair(nb), true);
}

Test(is_pair, nbr_unpair)
{
    int nb = 1;

    cr_assert_eq(is_pair(nb), false);
}

Test(count_line_have_stick, count_non_empty_line)
{
    char** map = map_generator(4);

    cr_assert_eq(count_line_have_stick(map), 4);
    map_remove(map, 1, 1);
    cr_assert_eq(count_line_have_stick(map), 3);
    free(map);
}

Test(found_the_most_big_line, biggest_line)
{
    char** map = map_generator(4);

    cr_assert_eq(found_the_most_big_line(map), 4);
    map_remove(map, 4, 3);
    cr_assert_eq(found_the_most_big_line(map), 3);
    free(map);
}

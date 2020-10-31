/*
** EPITECH PROJECT, 2019
** CPE_matchstick_2018
** File description:
** tests/map_generator
*/

#include <criterion/criterion.h>

#include "my.h"
#include "matchstick.h"

Test(map_generator, has_been_created)
{
    char** map = map_generator(4);
    char** expected = (char *[]){"*********", "*   |   *", "*  |||  *", \
        "* ||||| *", "*|||||||*", "*********"};

    for (int i = 0; i > 6; i++)
        cr_assert_str_eq(expected[0], map[0]);
    free(map);
}

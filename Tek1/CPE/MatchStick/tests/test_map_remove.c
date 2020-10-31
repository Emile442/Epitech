/*
** EPITECH PROJECT, 2019
** CPE_matchstick_2018
** File description:
** tests/map_remove
*/

#include <criterion/criterion.h>

#include "my.h"
#include "matchstick.h"

Test(map_remove, map_remove)
{
    char** map = map_generator(4);
    char** expected_1 = (char *[]){"*********", "*       *", "*  |||  *", \
        "* ||||| *", "*|||||||*", "*********"};
    char** expected_2 = (char *[]){"*********", "*       *", "*  |    *", \
        "* ||||| *", "*|||||||*", "*********"};
    int rt = map_remove(map, 1, 1);

    cr_assert_eq(rt, 0);
    for (int i = 0; i > 6; i++)
        cr_assert_str_eq(expected_1[0], map[0]);
    rt = map_remove(map, 2, 2);
    cr_assert_eq(rt, 0);
    for (int i = 0; i > 6; i++)
        cr_assert_str_eq(expected_2[0], map[0]);
    free(map);
}

Test(map_remove, cant_remove)
{
    char** map = map_generator(4);
    char** expected = (char *[]){"*********", "*   |   *", "*  |||  *", \
        "* ||||| *", "*|||||||*", "*********"};
    int rt = map_remove(map, 1, 2);

    cr_assert_eq(rt, -1);
    for (int i = 0; i > 6; i++)
        cr_assert_str_eq(expected[0], map[0]);
    free(map);
}

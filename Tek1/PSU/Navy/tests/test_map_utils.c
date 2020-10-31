/*
** EPITECH PROJECT, 2019
** PSU_navy_2018
** File description:
** test_map_utils
*/

#include <criterion/criterion.h>
#include "navy.h"

Test(hit, basic_test)
{
    char **map = initialize_map();
    int y = 1;
    int x = 1;

    cr_assert(map[x][y] == '.');
    hit(map, x, y);
    cr_assert(map[x][y] == 'x');
}

Test(missed, basic_test)
{
    char **map = initialize_map();
    int y = 1;
    int x = 1;

    cr_assert(map[x][y] == '.');
    missed(map, x, y);
    cr_assert(map[x][y] == 'o');
}

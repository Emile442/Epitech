/*
** EPITECH PROJECT, 2019
** test
** File description:
** get map
*/

#include <criterion/criterion.h>
#include "navy.h"

Test(initialize_map, basic_test)
{
    char **map = initialize_map();
    int y = 0;
    int x = 0;

    for (y = 0; map[y]; y++) {
        for (x = 0; map[y][x]; x++)
            cr_assert(map[y][x] == '.');
        cr_assert(x == 8);
    }
    cr_assert(y == 8);
}

Test(add_ship_to_map, basic_test)
{
    char **map = initialize_map();
    char line[7];

    line[0] = 2;
    line[2] = 2;
    line[3] = 0;
    line[5] = 2;
    line[6] = 1;
    cr_assert(add_ship_to_map(line, map));
    cr_assert(map[0][2] == '2');
    cr_assert(map[1][2] == '2');
}

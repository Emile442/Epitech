/*
** EPITECH PROJECT, 2019
** PSU_navy_2018
** File description:
** test_map_gameover
*/

#include <criterion/criterion.h>
#include "navy.h"

Test(gameover, basic_test)
{
    char **map = get_map_from_file("pos");

    cr_assert(map[0][2] == '2');
    hit(map, 0, 2);
    hit(map, 1, 2);
    for (int i = 4; i != 8; i++)
        hit(map, i, 1);
    for (int i = 3; i != 6; i++)
        hit(map, 3, i);
    cr_assert(!gameover(map));
    for (int i = 3; i != 8; i++)
        hit(map, 6, i);
    cr_assert(gameover(map));
}

/*
** EPITECH PROJECT, 2019
** PSU_navy_2018
** File description:
** test_map_verify_local_attack
*/

#include <criterion/criterion.h>
#include "navy.h"

Test(verify_local_attack, basic_test)
{
    char **map = initialize_map();
    char line[7];

    line[0] = 2;
    line[2] = 2;
    line[3] = 0;
    line[5] = 2;
    line[6] = 1;
    add_ship_to_map(line, map);
    cr_assert(verify_local_attack(map, 0, 2));
    cr_assert(!verify_local_attack(map, 0, 3));
}

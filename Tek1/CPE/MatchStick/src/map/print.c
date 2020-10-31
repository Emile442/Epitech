/*
** EPITECH PROJECT, 2019
** CPE_matchstick_2018
** File description:
** map/print
*/

#include "my.h"
#include "matchstick.h"

void map_print(char** map)
{
    for (int i = 0; map[i]; i++) {
        my_printf("%s\n", map[i]);
    }
}

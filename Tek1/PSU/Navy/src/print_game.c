/*
** EPITECH PROJECT, 2019
** PSU_navy_2018
** File description:
** print_map
*/

#include "navy.h"

void print_game(char** map, char** enemy_map)
{
    my_printf("my positions:\n");
    print_map(map);
    my_printf("enemy's positions:\n");
    print_map(enemy_map);
}

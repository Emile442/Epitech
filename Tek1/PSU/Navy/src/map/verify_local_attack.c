/*
** EPITECH PROJECT, 2019
** PSU_navy_2018
** File description:
** verify_local_attack
*/

#include "navy.h"

int verify_local_attack(char** map, int x, int y)
{
    if (map[x][y] != '.' && map[x][y] != 'o' && map[x][y] != 'x') {
        hit(map, x, y);
        return (true);
    }
    missed(map, x, y);
    return (false);
}

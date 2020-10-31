/*
** EPITECH PROJECT, 2019
** PSU_navy_2018
** File description:
** utils
*/

#include "navy.h"

void hit(char** map, int x, int y)
{
    map[x][y] = 'x';
}

void missed(char** map, int x, int y)
{
    map[x][y] = 'o';
}

/*
** EPITECH PROJECT, 2019
** PSU_navy_2018
** File description:
** gameover
*/

#include "navy.h"

static int detect_c(char c)
{
    if (c == 'x')
        return (true);
    return (false);
}

int gameover(char** map)
{
    int status = 0;

    for (int i = 0; map[i]; i++)
        for (int j = 0; map[i][j]; j++)
            status += detect_c(map[i][j]);
    return (status == 14 ? true : false);
}

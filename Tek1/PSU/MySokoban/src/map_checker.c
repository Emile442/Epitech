/*
** EPITECH PROJECT, 2018
** map_checker
** File description:
** Map Checker
*/

#include <ncurses.h>
#include <stdlib.h>

#include "my.h"
#include "sokoban.h"

void exit_map(void)
{
    endwin();
    exit(EPI_FAILURE);
}

void check_map(map_t *map, info_t *info)
{
    info->player = 0;
    info->storage = 0;
    info->box = 0;

    for (int i = 0; map->raw[i]; i++) {
        if (map->raw[i] == 'P')
            info->player++;
        if (map->raw[i] == 'X')
            info->box++;
        if (map->raw[i] == 'O')
            info->storage++;
        if (map->raw[i] != 'P' && map->raw[i] != 'X' && map->raw[i] != 'O'
            && map->raw[i] != '#' && map->raw[i] != ' ' && map->raw[i] != '\n')
            exit_map();
    }
    if (info->player != 1)
        exit_map();
    if (info->storage == 0 || info->box == 0)
        exit_map();
    if (info->storage != info->box)
        exit_map();
}
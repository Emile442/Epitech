/*
** EPITECH PROJECT, 2018
** maps_info
** File description:
** Maps Info
*/

#include <stdbool.h>
#include <stdlib.h>
#include "my.h"

char *get_map(char* buff)
{
    int i = 0;

    while (buff[i] != '\n')
        i++;
    return (&buff[i + 1]);
}

int map_length(char* const map)
{
    char tmp[100];
    int length = 0;

    for (int i = 0; map[i] != '\n'; i++)
        tmp[i] = map[i];
    length = my_getnbr(tmp);
    if (length == 0)
        exit(EPI_FAILURE);
    return (length);
}

int map_width(char* const map, bool mode)
{
    int length = map_length(map);
    int line = 0;
    int cols = 0;

    for (int i = 0; line != 2; i++) {
        if (line != 0)
            cols++;
        if (map[i] == '\n')
            line++;
    }
    if (mode)
        return (cols);
    return (cols - 1);
}

int map_size(char* const map, bool mode)
{
    return (map_length(map) * map_width(map, mode));
}
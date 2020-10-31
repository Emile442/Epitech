/*
** EPITECH PROJECT, 2018
** maps_transform
** File description:
** Transform map
*/

#include <stdlib.h>
#include "my.h"
#include "bsq.h"

void char_convert(coord_t *coord, int map_c, char* const map, int** new_map)
{
    if (map[map_c] == '.')
        new_map[coord->i][coord->j] = 1;
    else if (map[map_c] == 'o')
        new_map[coord->i][coord->j] = 0;
}

void map_converter(int row, int col, char* const map, int** new_map)
{
    char* map_tmp = malloc(sizeof(char) * my_strlen(map));
    coord_t *coord = malloc(sizeof(coord_t));
    int map_c = 0;
    int k = 0;

    for (int i = 0; map[i]; i++) {
        if (map[i] != '\n') {
            map_tmp[k] = map[i];
            k++;
        }
    }
    for (coord->i = 0; row > coord->i; coord->i++) {
        for (coord->j = 0; col > coord->j; coord->j++) {
            char_convert(coord, map_c, map_tmp, new_map);
            map_c++;
        }
    }
}

void init_init_calc(int row, int col, coord_t *init)
{
    init->i = 1;
    init->j = 1;
    init->k = 0;
    if (row == 1 || col == 1) {
        init->i = 0;
        init->j = 0;
        init->k = 1;
    }
}

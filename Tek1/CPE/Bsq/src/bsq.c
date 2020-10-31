/*
** EPITECH PROJECT, 2018
** bsq
** File description:
** BSQ
*/

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <sys/stat.h>

#include "my.h"
#include "bsq.h"

void found_biggest_square(coord_t *c, int** new_map, square_t *bsq, int mode)
{
    if (new_map[c->i][c->j]) {
        if (mode == 1)
            new_map[c->i][c->j] = min(new_map[c->i][c->j], new_map[c->i][c->j],
            new_map[c->i][c->j]) + 1;
        else
            new_map[c->i][c->j] = min(new_map[c->i - 1][c->j - 1],
            new_map[c->i - 1][c->j], new_map[c->i][c->j - 1]) + 1;
        if (new_map[c->i][c->j] > bsq->size) {
            bsq->size = new_map[c->i][c->j];
            bsq->x = c->i;
            bsq->y = c->j;
        }
    }
}

void print(coord_t *coord, square_t *bsq, int** new_map, char* print_map)
{
    if (range(bsq->x - (bsq->size - 1), bsq->x, coord->i)
    && range(bsq->y - (bsq->size - 1), bsq->y, coord->j)) {
        print_map[coord->k] = 'x';
    } else {
        if (new_map[coord->i][coord->j] == 1)
            print_map[coord->k] = '.';
        else
            print_map[coord->k] = 'o';
    }
}

void print_resolve_map(int row, int col, char* const map, square_t *bsq_square)
{
    coord_t *coord = malloc(sizeof(coord_t));
    int** new_map = malloc(sizeof(int*) * row);
    int test;
    char* print_map = malloc(sizeof(char) * ((row * col) + row + 1));

    coord->k = 0;
    for (int i = 0; row > i; i++)
        new_map[i] = malloc(sizeof(int) * col);
    map_converter(row, col, map, new_map);
    for (int i = 0; row > i; i++) {
        for (int j = 0; col > j; j++) {
            coord->i = i;
            coord->j = j;
            print(coord, bsq_square, new_map, print_map);
            coord->k++;
        }
        print_map[coord->k] = '\n';
        coord->k++;
    }
    write(1, print_map, ((row * col) + row));
}

void calc(char* const map, int row, int col)
{
    square_t *bsq_square = malloc(sizeof(square_t));
    coord_t *coord = malloc(sizeof(coord_t));
    coord_t *init = malloc(sizeof(coord_t));
    int** new_map = malloc(sizeof(int*) * row);
    int map_c = 0;
    bool last;

    bsq_square->size = 0;
    for (int i = 0; row > i; i++)
        new_map[i] = malloc(sizeof(int) * col);
    map_converter(row, col, map, new_map);
    init_init_calc(row, col, init);
    for (int i = init->i; row > i; i++) {
        for (int j = init->j; col > j; j++) {
            coord->i = i;
            coord->j = j;
            found_biggest_square(coord, new_map, bsq_square, init->k);
        }
    }
    print_resolve_map(row, col, map, bsq_square);
    free(bsq_square);
}

void bsq(char *file)
{
    char* buff;
    char* map;
    struct stat sb;
    int size_file = 0;

    if (stat(file, &sb) == -1)
        exit(EPI_FAILURE);
    size_file = sb.st_size;
    buff = malloc(sizeof(char) * size_file + 1);
    fs_read_file(fs_open_file(file), buff, size_file);
    map = malloc(sizeof(char) * map_size(buff, true));
    map = get_map(buff);
    calc(map, map_length(buff), map_width(buff, false));
}

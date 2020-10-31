/*
** EPITECH PROJECT, 2018
** my
** File description:
** BSQ headear
*/

#include <stdbool.h>

#ifndef BSQ_H
#define BSQ_H
typedef struct s_coord {
    int i;
    int j;
    int k;
} coord_t;
typedef struct s_square {
    int x;
    int y;
    int size;
} square_t;
int fs_open_file(char const *filepath);
void fs_read_file(int fd, char *buffer, int size);
char *get_map(char* buff);
int map_length(char* const map);
int map_width(char* const map, bool mode);
int map_size(char* const map, bool mode);
void map_converter(int row, int col, char* const map, int** new_map);
bool range(int a, int b, int value);
int min(int a, int b, int c);
void bsq(char *file);
void init_init_calc(int row, int col, coord_t *init);
#endif
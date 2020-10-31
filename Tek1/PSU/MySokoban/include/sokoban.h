/*
** EPITECH PROJECT, 2018
** my
** File description:
** BSQ headear
*/

#include <stdbool.h>

#ifndef SOKOBAN_H
#define SOKOBAN_H
typedef struct s_coord {
    int x;
    int y;
    char c;
} coord_t;

typedef struct s_info {
    int player;
    int storage;
    int box;
} info_t;

typedef struct s_map {
    int row;
    int col;
    int size;
    int storage;
    char** plan;
    char* raw;
} map_t;

typedef struct s_game {
    coord_t *player;
    coord_t *last;
    map_t *map;
    map_t *backup;
    info_t *info;
    int score;
    int stop;
    int restart;
    int loose;
    int win;
} game_t;

int fs_open_file(char const *filepath);
void fs_read_file(int fd, char *buffer, int size);
int get_filesize(char* const file);
int get_map_length(char* const map);
int get_map_width(char* const map);
void set_map(map_t *map, char* const file);
void set_player(coord_t *player, map_t *map);
void display_map(map_t *map);
void set_last(coord_t *last, coord_t *player);
void update_last(coord_t *last, coord_t *player, map_t *map);
bool can_move(coord_t *coord, map_t *map);
void up_player(game_t *game);
void down_player(game_t *game);
void right_player(game_t *game);
void left_player(game_t *game);
bool is_box(coord_t *coord, map_t *map);
bool is_storage(coord_t *coord, map_t *map);
void check_storage(game_t *game);
void move_box(game_t *game, coord_t *actual, coord_t *new);
void move_player(game_t *game, coord_t *new);
void move_object(game_t *game, coord_t *new, coord_t *front);
void check_loose(game_t *game);
void check_win(game_t *game);
void check_map(map_t *map, info_t *info);
void sokoban(char* const file);
game_t *init_game(char* const file);
void exit_map(void);
#endif
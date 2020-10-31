/*
** EPITECH PROJECT, 2018
** maps
** File description:
** Map
*/

#include <unistd.h>
#include <stdlib.h>
#include <stdbool.h>
#include <sys/stat.h>
#include <ncurses.h>

#include "my.h"
#include "sokoban.h"

void static set_map2(map_t *map)
{
    for (int i = 0; i <= map->row; i++) {
        map->plan[i] = malloc(sizeof(char) * map->col + 1);
    }
    for (int i = 0; map->raw[i]; i++)
        if (map->raw[i] == 'O')
            map->storage++;
}

void set_map(map_t *map, char* const file)
{
    int map_c = 0;
    int j = 0;

    map->size = get_filesize(file);
    map->raw = malloc(sizeof(char) * map->size + 1);
    fs_read_file(fs_open_file(file), map->raw, map->size);
    map->row = get_map_length(map->raw);
    map->col = get_map_width(map->raw);
    map->plan = malloc(sizeof(char*) * map->row);
    map->storage = 0;
    set_map2(map);
    for (int i = 0; i <= map->row; i++) {
        for (j = 0; map->raw[map_c] != '\n'; j++) {
            map->plan[i][j] = map->raw[map_c];
            map_c++;
        }
        map->plan[i][j] = map->raw[map_c];
        map->plan[i][j + 1] = '\0';
        map_c++;
        j = 0;
    }
}

void display_map(map_t *map)
{
    char *str = "Enlarge the terminal to display the whole map";

    clear();
    if (LINES < map->row || COLS < map->col) {
        mvprintw(LINES / 2, COLS / 2 - (my_strlen(str) / 2), str);
    } else {
        for (int i = 0; i <= map->row; i++) {
            mvprintw(i, 0, map->plan[i]);
        }
    }
    curs_set(0);
    refresh();
}

void static check_storage2(game_t *game, int i, int j)
{
    if (game->backup->plan[i][j] == 'O' && game->map->plan[i][j] == ' ') {
        game->map->plan[i][j] = 'O';
    }
}

void check_storage(game_t *game)
{
    int c = 0;

    for (int i = 0; i <= game->map->row; i++) {
        for (int j = 0; j < game->map->col; j++) {
            check_storage2(game, i, j);
        }
    }
}
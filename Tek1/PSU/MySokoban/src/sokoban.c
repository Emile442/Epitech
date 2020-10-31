/*
** EPITECH PROJECT, 2018
** sokoban
** File description:
** Sokoban
*/

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <sys/stat.h>
#include <ncurses.h>

#include "my.h"
#include "sokoban.h"

game_t *init_game(char* const file)
{
    game_t *game = malloc(sizeof(game_t));

    game->map = malloc(sizeof(map_t));
    game->backup = malloc(sizeof(map_t));
    game->last = malloc(sizeof(coord_t));
    game->player = malloc(sizeof(coord_t));
    game->info = malloc(sizeof(info_t));
    set_map(game->map, file);
    set_map(game->backup, file);
    set_player(game->player, game->map);
    set_last(game->last, game->player);
    game->score = 0;
    game->loose = 0;
    game->win = 0;
    game->stop = 0;
}

void reset_game(game_t *game)
{
    clear();
    game->map = game->backup;
    set_player(game->player, game->map);
    set_last(game->last, game->player);
    game->score = 0;
    display_map(game->map);
}

void static event_lister(game_t *game)
{
    int key = getch();

    if (key == ' ') {
        game->restart = 1;
    }
    if (key == 'q') {
        game->stop = 1;
    }
    if (key == '\033') {
        getch();
        key = getch();
        if (key == 'A')
            up_player(game);
        if (key == 'B')
            down_player(game);
        if (key == 'C')
            right_player(game);
        if (key == 'D')
            left_player(game);
    }
}

void static quit_game(game_t *game)
{
    if (game->loose != 0 || game->win == 1) {
        endwin();
        if (game->loose != 0) {
            exit(1);
        } else {
            exit(0);
        }
    }
}

void sokoban(char* const file)
{
    game_t *game = init_game(file);
    char *str = "Enlarge the terminal to display the whole map";

    check_map(game->map, game->info);
    game->restart = 0;
    display_map(game->map);
    noecho();
    while (1) {
        event_lister(game);
        display_map(game->map);
        if (game->stop == 1 || game->restart == 1
            || game->loose != 0 || game->win == 1)
            break;
    };
    if (game->restart == 1)
        sokoban(file);
    quit_game(game);
}
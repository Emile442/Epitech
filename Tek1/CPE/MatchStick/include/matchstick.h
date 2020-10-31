/*
** EPITECH PROJECT, 2019
** CPE_matchstick_2018
** File description:
** MATCHSTICK
*/

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>

#ifndef MATCHSTICK_H_
#define MATCHSTICK_H_

#define MS_WIN (1)
#define MS_LOOSE (2)

typedef struct turn_s {
    int line;
    int match;
    int status;
} turn_t;

typedef struct game_s {
    char** map;
    int map_size;
    int match_limit;
} game_t;

int matchstick(game_t* game);

char** map_generator(int nb);
void map_print(char** map);
int map_remove(char** map, int line, int nb_matches);
int count_line_stick(char* line);
bool map_can_supr(char* line, int value, int limit);
bool can_select_line(char** map, int value, int limit);

game_t* game_new(char** params);
bool check_end_game(char** map);

int player_turn(game_t* game);
void ia_turn(game_t* game);

int found_the_most_big_line(char** map);
int count_line_have_stick(char** map);
bool is_pair(int nbr);

#endif /* !MATCHSTICK_H_ */

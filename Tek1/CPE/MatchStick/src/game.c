/*
** EPITECH PROJECT, 2019
** CPE_matchstick_2018
** File description:
** game
*/

#include "my.h"
#include "matchstick.h"

game_t* game_new(char** params)
{
    game_t* tmp = malloc(sizeof(game_t));

    tmp->map_size = my_getnbr(params[1]);
    tmp->match_limit = my_getnbr(params[2]);
    tmp->map = map_generator(tmp->map_size);
    return (tmp);
}

static bool check_end_game_2(char* line)
{
    for (int j = 0; line[j]; j++)
        if (line[j] == '|')
            return (true);
    return (false);
}

bool check_end_game(char** map)
{
    for (int i = 0; map[i]; i++)
        if (check_end_game_2(map[i]))
            return (false);
    return (true);
}

/*
** EPITECH PROJECT, 2019
** CPE_matchstick_2018
** File description:
** matchstick
*/

#include "my.h"
#include "matchstick.h"

int matchstick(game_t* game)
{
    bool player = true;
    int status = 0;

    map_print(game->map);
    while (!check_end_game(game->map)) {
        if (player) {
            status = player_turn(game);
            player = false;
        } else {
            ia_turn(game);
            player = true;
        }
        if (status == -1)
            return (0);
    }
    if (player)
        my_printf("I lost... snif... but I'll get you next time!!");
    else
        my_printf("You lost, too bad...");
    return (player ? MS_WIN : MS_LOOSE);
}

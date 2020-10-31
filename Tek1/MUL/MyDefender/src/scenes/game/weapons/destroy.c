/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2018
** File description:
** weapons/destroy
*/

#include "my_defender.h"

void weapons_destroy(game_t* game)
{
    if (game->weapons_count != 0) {
        for (int i = 0; i != game->weapons_count; i++)
            destroy_spt(game->weapons[i]);
    }
    free(game->weapons);
}

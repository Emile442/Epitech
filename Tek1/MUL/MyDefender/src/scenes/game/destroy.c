/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2018
** File description:
** game/destroy
*/

#include "my_defender.h"

void game_destroy(game_t* game)
{
    destroy_music(game->music);
    weapons_destroy(game);
    ennemy_destroy(game);
    hud_destroy(game->hud);
    destroy_spt(game->background);
    free(game);
}

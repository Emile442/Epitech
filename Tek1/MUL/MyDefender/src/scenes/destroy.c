/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2018
** File description:
** scenes/destroy
*/

#include "my_defender.h"

void scene_destroy(scene_t* scenes)
{
    home_destroy(scenes->home);
    game_destroy(scenes->game);
    pause_destroy(scenes->pause);
    free(scenes);
}

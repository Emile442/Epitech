/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2018
** File description:
** scenes/init
*/

#include "my_defender.h"

scene_t* scene_init(void)
{
    scene_t* scene = malloc(sizeof(scene_t));

    scene->home = home_init();
    scene->game = game_init();
    scene->pause = pause_init();
    scene->draw = &home_draw;
    return (scene);
}

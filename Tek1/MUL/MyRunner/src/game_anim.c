/*
** EPITECH PROJECT, 2018
** game_anim
** File description:
** Game Anim
*/

#include "my.h"
#include "my_runner.h"

void game_anim(window_t *current)
{
    parallax_anim(current->clock_list, current);
    if (sfClock_getElapsedTime(\
        current->clock_list->player).microseconds / 1000 > 60)
        player_anim(current);
    if (sfClock_getElapsedTime(current->clock_list->score).microseconds / \
        1000 > 1000)
        score_update(current);
    if (sfClock_getElapsedTime(current->clock_list->pumkin).microseconds / \
        1000 > 15)
        box_anim(current);
    update_frame(current);
}

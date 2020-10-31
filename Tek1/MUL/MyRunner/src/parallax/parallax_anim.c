/*
** EPITECH PROJECT, 2018
** parallax_anim
** File description:
** Parallax Anim
*/

#include "my.h"
#include "my_runner.h"


void item_anim(sfClock *clock_i, sprite_texture_t *actual, \
sprite_texture_t *copy, int fps)
{
    sfClock_restart(clock_i);
    actual->pos.x -= fps;
    sfSprite_setPosition(actual->sprite, actual->pos);
    copy->pos.x -= fps;
    sfSprite_setPosition(copy->sprite, copy->pos);
    if (actual->pos.x <= -1919)
        actual->pos.x = 1920;
    if (copy->pos.x <= -1919)
        copy->pos.x = 1920;

}

void parallax_anim(clock_list_t *clock, window_t *current)
{
    if (sfClock_getElapsedTime(clock->pr_ground).microseconds / 1000 > 15)
        item_anim(clock->pr_ground, current->parallax->ground, \
        current->parallax->ground_copy, 24);
    if (sfClock_getElapsedTime(clock->pr_foreground).microseconds / 1000 > 15)
        item_anim(clock->pr_foreground, \
        current->parallax->foreground, current->parallax->foreground_copy, 12);
    if (sfClock_getElapsedTime(clock->pr_midground).microseconds / 1000 > 30)
        item_anim(current->clock_list->pr_midground, \
        current->parallax->midground, current->parallax->midground_copy, 8);
}

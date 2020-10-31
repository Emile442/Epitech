/*
** EPITECH PROJECT, 2019
** MUL_my_runner_2018
** File description:
** box_actual
*/

#include "my.h"
#include "my_runner.h"

void box_anim(window_t *current)
{
    map_t *tmp = NULL;

    sfClock_restart(current->clock_list->pumkin);
    tmp = current->map;
    while (tmp) {
        if (tmp->value == 1 && tmp->entity->pos.x >= -100) {
            tmp->entity->pos.x -= 25;
            sfSprite_setPosition(tmp->entity->sprite, tmp->entity->pos);
        }
        tmp = tmp->next;
    }

}

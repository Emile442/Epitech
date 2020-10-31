/*
** EPITECH PROJECT, 2019
** MUL_my_runner_2018
** File description:
** box_actual
*/

#include "my.h"
#include "my_runner.h"

void box_draw(window_t *current)
{
    map_t *tmp = NULL;
    tmp = current->map;
    while (tmp) {
        if (tmp->value == 1)
            sfRenderWindow_drawSprite(current->window, \
            tmp->entity->sprite, NULL);
        tmp = tmp->next;
    }
}

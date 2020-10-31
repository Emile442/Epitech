/*
** EPITECH PROJECT, 2018
** box_waiting
** File description:
** Box Waiting
*/

#include "my.h"
#include "my_runner.h"

static void push_box(map_t **list, int value, sfVector2f pos)
{
    map_t* new_val = malloc(sizeof(map_t));

    new_val->value = value;
    if (value == 1) {
        new_val->entity = malloc(sizeof(sprite_texture_t));
        new_val->entity->pos = pos;
        new_val->entity->texture = sfTexture_createFromFile(\
        "assets/img/box.png", NULL);
        new_val->entity->sprite = sfSprite_create();
        sfSprite_setTexture(new_val->entity->sprite, new_val->entity->texture, \
        sfTrue);
        sfSprite_setPosition(new_val->entity->sprite, new_val->entity->pos);
    }
    new_val->next = (*list);
    (*list) = new_val;
}

void box_waiting(window_t *current)
{
    for (int i = 1920; current->waiting; i += 300) {
        reverse_list(&current->map);
        push_box(&current->map, current->waiting->value, (sfVector2f){i, 805});
        reverse_list(&current->map);
        current->waiting = current->waiting->next;
    }
}

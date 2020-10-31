/*
** EPITECH PROJECT, 2018
** box_colision
** File description:
** Box collision detect
*/

#include "my.h"
#include "my_runner.h"

static void check_colision(window_t* current, sfSprite* box_sp)
{
    sfFloatRect player = sfSprite_getGlobalBounds(current->player->sprite);
    sfFloatRect box = sfSprite_getGlobalBounds(box_sp);

    player.width -= 50;
    if (sfFloatRect_intersects(&player, &box, NULL) == sfTrue)
        current->lives--;
}

void box_colision(window_t *current)
{
    map_t *tmp = NULL;

    tmp = current->map;
    while (tmp) {
        if (tmp->value == 1 && tmp->entity->pos.x >= -100) {
            check_colision(current, tmp->entity->sprite);
        }
        tmp = tmp->next;
    }
}

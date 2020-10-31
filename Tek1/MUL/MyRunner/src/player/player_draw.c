/*
** EPITECH PROJECT, 2018
** player_draw
** File description:
** Player Draw
*/

#include "my.h"
#include "my_runner.h"

void player_draw(window_t *current)
{
    sfSprite_setPosition(current->player->sprite, current->player->pos);
    sfRenderWindow_drawSprite(current->window, \
    current->player->sprite, NULL);
}

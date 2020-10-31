/*
** EPITECH PROJECT, 2018
** parallax_draw
** File description:
** Parallax Draw
*/

#include "my.h"
#include "my_runner.h"

void parallax_draw(window_t *current)
{
    sfRenderWindow_drawSprite(current->window, \
    current->parallax->background->sprite, NULL);
    sfRenderWindow_drawSprite(current->window, \
    current->parallax->midground->sprite, NULL);
    sfRenderWindow_drawSprite(current->window, \
    current->parallax->midground_copy->sprite, NULL);
    sfRenderWindow_drawSprite(current->window, \
    current->parallax->foreground->sprite, NULL);
    sfRenderWindow_drawSprite(current->window, \
    current->parallax->foreground_copy->sprite, NULL);
    sfRenderWindow_drawSprite(current->window, \
    current->parallax->ground->sprite, NULL);
    sfRenderWindow_drawSprite(current->window, \
    current->parallax->ground_copy->sprite, NULL);
}
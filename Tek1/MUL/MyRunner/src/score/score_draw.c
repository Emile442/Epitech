/*
** EPITECH PROJECT, 2018
** score_draw
** File description:
** Score Draw
*/

#include "my.h"
#include "my_runner.h"

void score_draw(window_t *current)
{
    sfRenderWindow_drawSprite(current->window, \
    current->scoreboard->score_img->sprite, NULL);
    sfRenderWindow_drawText(current->window, current->scoreboard->text, NULL);
}

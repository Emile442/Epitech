/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2018
** File description:
** pause/draw
*/

#include "my_defender.h"

void pause_draw(window_t *current)
{
    pause_t* pause = current->scenes->pause;

    sfRenderWindow_drawSprite(current->window, pause->background->sprite, NULL);
    pause_resume_button_draw(current);
    pause_home_button_draw(current);
    pause_quit_button_draw(current);
}

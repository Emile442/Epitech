/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2018
** File description:
** home/draw
*/

#include "my_defender.h"

void home_draw(window_t *current)
{
    home_t* home = current->scenes->home;

    sfRenderWindow_drawSprite(current->window, home->background->sprite, NULL);
    home_play_button_draw(current);
    home_quit_button_draw(current);
    if (current->click_action) {
        game_destroy(current->scenes->game);
        current->scenes->game = game_init();
        current->click_action = 0;
    }
}

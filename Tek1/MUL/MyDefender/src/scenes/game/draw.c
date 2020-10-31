/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2018
** File description:
** game/draw
*/

#include "my_defender.h"

void game_draw(window_t *current)
{
    game_t* game = current->scenes->game;

    game_keyboard_event(current);
    sfRenderWindow_drawSprite(current->window, game->background->sprite, NULL);
    game_enemy_draw(current);
    weapons_draw(current);
    if (game->delta_charlie->in_progress)
        draw_delta_charlie(current);
    hud_draw(current);
}

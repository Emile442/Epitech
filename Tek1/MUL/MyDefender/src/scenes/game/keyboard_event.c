/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2018
** File description:
** keyboard_event
*/

#include "my_defender.h"

void game_keyboard_event(window_t* current)
{
    if (current->event.type == sfEvtKeyReleased) {
        if (current->event.key.code == sfKeyEscape || \
current->event.key.code == sfKeySpace) {
            current->scenes->draw = &pause_draw;
            sfMusic_pause(current->scenes->game->music);
        }
        if (current->event.key.code == sfKeyQ)
            current->exit = true;
    }
}

/*
** EPITECH PROJECT, 2018
** player_listener
** File description:
** Player Listener
*/

#include "my.h"
#include "my_runner.h"

void player_listener(window_t *current)
{
    if (sfKeyboard_isKeyPressed(sfKeySpace)) {
        current->player->jump = true;
        current->player->spriteStep = -1;
        sfMusic_stop(current->player->jump_music);
        sfMusic_play(current->player->jump_music);
    }
}

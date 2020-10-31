/*
** EPITECH PROJECT, 2018
** player_anim
** File description:
** Player Anim
*/

#include "my.h"
#include "my_runner.h"

static void player_run(window_t *current)
{
    sfSprite_setTextureRect(current->player->sprite, \
    current->player->run_s[current->player->spriteStep]);
    if (current->player->spriteStep == 9)
        current->player->spriteStep = 4;
}

static void player_jump(window_t *current)
{
    sfSprite_setTextureRect(current->player->sprite, \
    current->player->jump_s[current->player->spriteStep]);
    current->player->pos = current->player->jump_p[current->player->spriteStep];
    if (current->player->spriteStep == 9) {
        current->player->jump = false;
        current->player->spriteStep = 3;
    }
}

void player_anim(window_t *current)
{
    sfClock_restart(current->clock_list->player);
    current->player->spriteStep++;
    if (current->player->jump)
        player_jump(current);
    else
        player_run(current);
}
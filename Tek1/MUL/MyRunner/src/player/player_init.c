/*
** EPITECH PROJECT, 2018
** player_init
** File description:
** Player init
*/

#include "my.h"
#include "my_runner.h"

void set_player_run_sprite(window_t *current)
{
    current->player->run_s[0] = set_scale(0, 0, 162, 365 + 162);
    current->player->run_s[1] = set_scale(0, 162, 204, 369 + 162);
    current->player->run_s[2] = set_scale(0, 366, 220, 358 + 162);
    current->player->run_s[3] = set_scale(0, 586, 239, 358 + 162);
    current->player->run_s[4] = set_scale(0, 825, 235, 363 + 162);
    current->player->run_s[5] = set_scale(0, 1060, 296, 368 + 162);
    current->player->run_s[6] = set_scale(0, 1356, 333, 360 + 162);
    current->player->run_s[7] = set_scale(0, 1689, 294, 329 + 162);
    current->player->run_s[8] = set_scale(0, 1983, 246, 366 + 162);
    current->player->run_s[9] = set_scale(0, 2229, 274, 352 + 162);
}

void set_player_jump_sprite(window_t *current)
{
    current->player->jump_s[0] = set_scale(0, 0 + 2503, 178, 525);
    current->player->jump_s[1] = set_scale(0, 178 + 2503, 210, 525);
    current->player->jump_s[2] = set_scale(0, 388 + 2503, 200, 525);
    current->player->jump_s[3] = set_scale(0, 588 + 2506, 211, 525);
    current->player->jump_s[4] = set_scale(0, 588 + 2506, 211, 525);
    current->player->jump_s[5] = set_scale(0, 588 + 2506, 211, 525);
    current->player->jump_s[6] = set_scale(0, 588 + 2506, 211, 525);
    current->player->jump_s[7] = set_scale(0, 803 + 2503, 195, 525);
    current->player->jump_s[8] = set_scale(0, 998 + 2503, 181, 525);
    current->player->jump_s[9] = set_scale(0, 1179 + 2503, 190, 525);
}

void set_player_jump_pos(window_t *current)
{
    current->player->jump_p[0] = (sfVector2f){400, 355};
    current->player->jump_p[1] = (sfVector2f){400, 355};
    current->player->jump_p[2] = (sfVector2f){400, 300};
    current->player->jump_p[3] = (sfVector2f){400, 240};
    current->player->jump_p[4] = (sfVector2f){400, 170};
    current->player->jump_p[5] = (sfVector2f){400, 170};
    current->player->jump_p[6] = (sfVector2f){400, 170};
    current->player->jump_p[7] = (sfVector2f){400, 170};
    current->player->jump_p[8] = (sfVector2f){400, 300};
    current->player->jump_p[9] = (sfVector2f){400, 355};
}

void set_player(window_t *current)
{
    current->player = malloc(sizeof(player_t));
    current->player->pos = (sfVector2f){400, 355};
    current->player->spriteStep = 0;
    current->player->jump = false;
    current->player->texture = sfTexture_createFromFile(\
    "assets/img/player/player.png", NULL);
    current->player->sprite = sfSprite_create();
    set_player_run_sprite(current);
    set_player_jump_sprite(current);
    set_player_jump_pos(current);
    current->player->jump_music = sfMusic_createFromFile(\
    "assets/music/player_jump.ogg");
    sfSprite_setTexture(current->player->sprite, \
    current->player->texture, sfTrue);
    sfSprite_setTextureRect(current->player->sprite, \
    current->player->run_s[current->player->spriteStep]);
}

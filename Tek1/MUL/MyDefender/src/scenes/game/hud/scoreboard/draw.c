/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2018
** File description:
** scoreboard/draw.c
*/

#include "my_defender.h"

void update_infos(info_t* infos)
{
    if (sfClock_getElapsedTime(infos->score->update).microseconds / 10000 > \
    100) {
        sfClock_restart(infos->score->update);
        infos->score->value += 1;
        sfText_setString(infos->score->text, str_with_num("Score: ", \
        infos->score->value));
    }
    if (sfClock_getElapsedTime(infos->money->update).microseconds / 1000 > \
    100) {
        sfClock_restart(infos->money->update);
        infos->money->value += 2;
        sfText_setString(infos->money->text, str_with_num("Money: $", \
        infos->money->value));
    }
    if (sfClock_getElapsedTime(infos->level->update).microseconds / 1000 > \
    100) {
        sfClock_restart(infos->level->update);
        sfText_setString(infos->level->text, str_with_num("Level: ", \
        infos->level->value));
    }
}

void draw_infos(window_t* current)
{
    info_t* infos = current->scenes->game->hud->infos;

    update_infos(infos);
    sfRenderWindow_drawText(current->window, infos->score->text, NULL);
    sfRenderWindow_drawText(current->window, infos->money->text, NULL);
    sfRenderWindow_drawText(current->window, infos->level->text, NULL);
}

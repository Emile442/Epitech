/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2018
** File description:
** enemy/draw
*/

#include "my_defender.h"

void move_ennemy(window_t* current, ennemy_t *enemy)
{
    move_up1(enemy);
    move_left1(enemy);
    move_up2(enemy);
    move_left2(enemy);
    move_down(enemy);
    if (move_left3(enemy)) {
        current->scenes->draw = &home_draw;
        current->click_action = 1;
        sfMusic_stop(current->scenes->game->music);
    }
}

void creat_enemy(window_t* current)
{
    for (;sfClock_getElapsedTime(current->scenes->game->add_enemy)\
.microseconds / 1000 > 1000 &&\
current->scenes->game->spawn\
!= current->scenes->game->hud->infos->level->value * 5     \
; current->scenes->game->spawn++) {
        sfClock_restart(current->scenes->game->add_enemy);
        game_enemy_add(current);
    }
}

int move(window_t *current, ennemy_t **enemy, int i)
{
    if (sfClock_getElapsedTime(enemy[i]->move).microseconds / 100 > 100) {
        sfClock_restart(enemy[i]->move);
        move_ennemy(current, enemy[i]);
        if (enemy[i]->status == 6)
            delete_ennemy(current->scenes->game, i);
        if (current->scenes->game->enemy_count == 0) {
            current->scenes->game->hud->infos->level->value += 1;
            current->scenes->game->spawn = 0;
            return (1);
        }
    }
    return (0);
}

void game_enemy_draw(window_t* current)
{
    ennemy_t** enemy = NULL;

    creat_enemy(current);
    enemy = current->scenes->game->enemy;
    for (int i = 0; i != current->scenes->game->enemy_count; i++) {
        sfSprite_setPosition(enemy[i]->spt->sprite, enemy[i]->position);
        sfSprite_setRotation(enemy[i]->spt->sprite, enemy[i]->angle);
        sfRenderWindow_drawSprite(current->window, enemy[i]->spt->sprite, NULL);
        if (move(current, enemy, i) != 0)
            return;
    }
}

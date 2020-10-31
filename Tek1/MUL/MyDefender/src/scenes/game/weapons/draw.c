/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2018
** File description:
** weapons/draw
*/

#include "my_defender.h"

void shot_or_not(game_t *game, sfVector2f pos_weapons, int dist)
{
    int tmp = 0;
    int index = -1;

    for (int j = 0; j != game->enemy_count; j++)
        if ((tmp = range_turret(pos_weapons, dist, j, game)) != -1)
            index = tmp;
    if (index != -1) {
        game->enemy[index]->life -= 10;
        game->hud->infos->score->value += 10;
        game->hud->infos->money->value += 10;
        if (game->enemy[index]->life <= 0) {
            game->hud->infos->score->value += 20;
            game->hud->infos->money->value += 20;
            delete_ennemy(game, index);
        }
        if (game->enemy_count == 0) {
            game->hud->infos->level->value++;
            game->spawn = 0;
        }
    }
}

void weapons_shot(game_t *game, int i)
{
    sfVector2f pos_weapons = {0, 0};
    sfVector2f pos_ennemy = {0, 0};
    int dist = 0;

    if (game->enemy_count == 0)
        return;
    pos_weapons.x = sfSprite_getPosition(game->weapons[i]->sprite).x;
    pos_weapons.y = sfSprite_getPosition(game->weapons[i]->sprite).y;
    pos_ennemy.x = sfSprite_getPosition(game->enemy[0]->spt->sprite).x;
    pos_ennemy.y = sfSprite_getPosition(game->enemy[0]->spt->sprite).y;
    dist = calc_dist((int)pos_ennemy.x, \
(int)pos_ennemy.y, (int)pos_weapons.x, (int)pos_weapons.y);
    shot_or_not(game, pos_weapons, dist);
}

void move_rect(game_t *game, int max, int offset, int index)
{
    if (game->weapons[index]->rect.left < max)
        game->weapons[index]->rect.left += offset;
    else
        game->weapons[index]->rect.left = 0;
}

void rect_weapons_and_shot(game_t *game, int i)
{
    if (sfClock_getElapsedTime(game->weapons[i]->my_clock)\
.microseconds / 1000 > 500) {
        weapons_shot(game, i);
        sfClock_restart(game->weapons[i]->my_clock);
        move_rect(game, 4608, 138, i);
        sfSprite_setTextureRect(game->weapons[i]->sprite, \
game->weapons[i]->rect);
    }
}

void weapons_draw(window_t* current)
{
    game_t* game = current->scenes->game;
    int i = 0;

    if (game->weapons_count != 0) {
        for (i = 0; i != game->weapons_count; i++) {
            rect_weapons_and_shot(game, i);
            sfRenderWindow_drawSprite(current->window, \
            game->weapons[i]->sprite, NULL);
        }
    }
}

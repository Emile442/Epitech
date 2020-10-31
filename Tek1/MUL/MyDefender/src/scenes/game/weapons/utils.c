/*
** EPITECH PROJECT, 2019
** utils
** File description:
** utils
*/

#include "my_defender.h"

int my_sqrt(int nbr)
{
    int i = 0;

    for (; i < nbr; i++)
        if (i*i >= nbr)
            break;
    return (i);
}

int calc_dist(int ennemy_x, int ennemy_y, int weapon_x, int weapon_y)
{
    int calc = 0;
    int pow1 = (ennemy_x - weapon_x) * (ennemy_x - weapon_x);
    int pow2 = (ennemy_y - weapon_y) * (ennemy_y - weapon_y);

    calc = my_sqrt(pow1 + pow2);
    return (calc);
}

void delete_ennemy(game_t *game, int i)
{
    ennemy_t *tmp;
    tmp = game->enemy[i];

    for (; i < game->enemy_count; i++) {
        game->enemy[i] = game->enemy[i + 1];
        game->enemy[i + 1] = tmp;
    }
    destroy_one_ennemy(game, i);
    game->enemy[i] = NULL;
    game->enemy_count--;
}

int range_turret(sfVector2f pos_weapons, int dist, int j, game_t *game)
{
    int tmp_dist = 0;
    sfVector2f pos_ennemy = {0, 0};

    pos_ennemy.x = sfSprite_getPosition(game->enemy[j]->spt->sprite).x;
    pos_ennemy.y = sfSprite_getPosition(game->enemy[j]->spt->sprite).y;
    if (pos_ennemy.x <= pos_weapons.x + 300 && \
pos_ennemy.x >= pos_weapons.x - 300 && \
pos_ennemy.y <= pos_weapons.y + 300 && \
pos_ennemy.y >= pos_weapons.y - 300) {
        tmp_dist = calc_dist((int)pos_ennemy.x, (int)pos_ennemy.y, \
(int)pos_weapons.x, (int)pos_weapons.y);
        if (dist >= tmp_dist){
            dist = tmp_dist;
            return (j);
        }
    }
    return (-1);
}

void set_start_angle(game_t *game, sfVector2f pos, int angle)
{
    if (pos.x == 824)
        sfSprite_setRotation(\
game->weapons[game->weapons_count]->sprite, angle + 120);
    if (pos.x == 1594)
        sfSprite_setRotation(\
game->weapons[game->weapons_count]->sprite, angle + 120);
    if (pos.x == 454)
        sfSprite_setRotation(\
game->weapons[game->weapons_count]->sprite, angle + 40);
    if (pos.x == 1224)
        sfSprite_setRotation(\
game->weapons[game->weapons_count]->sprite, angle + 40);
}
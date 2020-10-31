/*
** EPITECH PROJECT, 2019
** utils
** File description:
** utils
*/

#include "my_defender.h"

void ennemy1(ennemy_t *enemy)
{
    sfVector2f pos = {64, 64};

    enemy->spt = init_spt("assets/img/enemy_4.png");
    sfSprite_setOrigin(enemy->spt->sprite, pos);
    enemy->angle = 270;
    enemy->life = 90;
    enemy->zone = 0;
    enemy->position = (sfVector2f){264, 950};
    enemy->speed = 1.5;
    enemy->status = 0;
    enemy->move = sfClock_create();
}

void ennemy2(ennemy_t *enemy)
{
    sfVector2f pos = {64, 64};

    enemy->spt = init_spt("assets/img/enemy_3.png");
    sfSprite_setOrigin(enemy->spt->sprite, pos);
    enemy->angle = 270;
    enemy->life = 90;
    enemy->zone = 0;
    enemy->position = (sfVector2f){264, 950};
    enemy->speed = 2.5;
    enemy->status = 0;
    enemy->move = sfClock_create();
}

void ennemy3(ennemy_t *enemy)
{
    sfVector2f pos = {64, 64};

    enemy->spt = init_spt("assets/img/enemy_2.png");
    sfSprite_setOrigin(enemy->spt->sprite, pos);
    enemy->angle = 270;
    enemy->life = 190;
    enemy->zone = 0;
    enemy->position = (sfVector2f){264, 950};
    enemy->speed = 1;
    enemy->status = 0;
    enemy->move = sfClock_create();
}

void boss_level(ennemy_t *enemy)
{
    sfVector2f pos = {64, 64};

    enemy->spt = init_spt("assets/img/enemy_1.png");
    sfSprite_setOrigin(enemy->spt->sprite, pos);
    enemy->angle = 270;
    enemy->life = 400;
    enemy->zone = 0;
    enemy->position = (sfVector2f){264, 950};
    enemy->speed = 1.25;
    enemy->status = 0;
    enemy->move = sfClock_create();
}
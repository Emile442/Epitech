/*
** EPITECH PROJECT, 2019
** move
** File description:
** move
*/

#include "my_defender.h"

void move_up1(ennemy_t* enemy)
{
    if (enemy->status == 0 && enemy->position.x == 264 &&\
(enemy->position.y <= 950 && enemy->position.y > 756))
        enemy->position.y -= enemy->speed;
    if (enemy->status == 0 && enemy->position.x == 264 &&
    enemy->position.y <= 756) {
        enemy->position.y = 756;
        enemy->angle += 90;
        enemy->status = 1;
    }
}

void move_up2(ennemy_t* enemy)
{
    if (enemy->status == 2 && enemy->position.x >= 624 &&\
(enemy->position.y <= 756 && enemy->position.y > 116)) {
        enemy->position.y -= enemy->speed;
        enemy->zone = 2;
    }
    if (enemy->status == 2 && enemy->position.x >= 624 &&
    enemy->position.y <= 116) {
        enemy->position.y = 116;
        enemy->angle += 90;
        enemy->status = 3;
    }
}

void move_down(ennemy_t* enemy)
{
    if (enemy->status == 4 && enemy->position.x >= 1384\
&& (enemy->position.y >= 116 && enemy->position.y < 844)) {
        enemy->position.y += enemy->speed;
        enemy->zone = 4;
    }
    if (enemy->status == 4 && enemy->position.x >= 1384 &&
    (enemy->position.y >= 844)) {
        enemy->position.y = 844;
        enemy->angle -= 90;
        enemy->status = 5;
    }
}

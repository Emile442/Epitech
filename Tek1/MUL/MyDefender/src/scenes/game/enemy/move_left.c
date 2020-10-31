/*
** EPITECH PROJECT, 2019
** move left
** File description:
** move left
*/

#include "my_defender.h"

void move_left1(ennemy_t* enemy)
{
    if (enemy->status == 1 && enemy->position.y <= 756 &&\
(enemy->position.x >= 264 && enemy->position.x < 624)) {
        enemy->position.x += enemy->speed;
        enemy->zone = 1;
    }
    if (enemy->status == 1 && enemy->position.x >= 624 &&\
enemy->position.y <= 756){
        enemy->position.x = 624;
        enemy->angle -= 90;
        enemy->status = 2;
    }
}

void move_left2(ennemy_t* enemy)
{
    if (enemy->status == 3 && enemy->position.y <= 116 &&\
(enemy->position.x >= 624 && enemy->position.x < 1384)) {
        enemy->position.x += enemy->speed;
        enemy->zone = 3;
    }
    if (enemy->status == 3 && enemy->position.y <= 116 &&\
enemy->position.x >= 1384) {
        enemy->position.y = 116;
        enemy->angle += 90;
        enemy->status = 4;
    }
}

bool move_left3(ennemy_t* enemy)
{
    if (enemy->status == 5 && enemy->position.y >= 844 &&\
(enemy->position.x >= 1384 && enemy->position.x < 2000)) {
        enemy->position.x += enemy->speed;
        enemy->zone = 5;
    }
    if (enemy->status == 5 && enemy->position.y >= 844 &&\
enemy->position.x >= 2000) {
        enemy->angle = 270;
        enemy->status = 0;
        enemy->status = 6;
        return (true);
    }
    return (false);
}

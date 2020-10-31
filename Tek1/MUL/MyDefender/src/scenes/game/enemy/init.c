/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2018
** File description:
** ennemi/init
*/

#include "my_defender.h"

ennemy_t** game_enemy_init(void)
{
    ennemy_t** enemy = malloc(sizeof(ennemy_t) * 200);

    return (enemy);
}

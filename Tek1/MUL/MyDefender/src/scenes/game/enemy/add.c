/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2018
** File description:
** ennemi/add
*/

#include "my_defender.h"

ennemy_t* init_enemy(game_t* game)
{
    ennemy_t* enemy = malloc(sizeof(ennemy_t));
    int tmp = rand()%3;
    int level = game->hud->infos->level->value;

    if (level % 5 == 0) {
        boss_level(enemy);
        return (enemy);
    }
    if (tmp == 0)
        ennemy1(enemy);
    else if (tmp == 1)
        ennemy2(enemy);
    else
        ennemy3(enemy);
    enemy->life += level * 10;
    return (enemy);
}

void game_enemy_add(window_t* current)
{
    game_t* game = current->scenes->game;
    game->enemy[game->enemy_count] = init_enemy(game);
    game->enemy_count++;
}

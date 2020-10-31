/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2018
** File description:
** weapons/destroy
*/

#include "my_defender.h"

void destroy_one_ennemy(game_t *game, int i)
{
    destroy_spt(game->enemy[i]->spt);
    sfClock_destroy(game->enemy[i]->move);
    free(game->enemy[i]);
}

void ennemy_destroy(game_t* game)
{
    if (game->enemy_count != 0) {
        for (int i = 0; i != game->enemy_count; i++) {
            destroy_spt(game->enemy[i]->spt);
            sfClock_destroy(game->enemy[i]->move);
            free(game->enemy[i]);
        }
    }
    sfClock_destroy(game->add_enemy);
    free(game->enemy);
}

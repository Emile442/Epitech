/*
** EPITECH PROJECT, 2020
** destroy_player.c
** File description:
** destroy_player
*/

#include "player.h"

void destroy_players(player_t *player)
{
    player_t *temp;
    if (!player)
        return;
    if (player->next) {
        temp = player->next;
        if (player->next->next)
            player->next = player->next->next;
        free(temp);
    }
    free(player);
    return;
}

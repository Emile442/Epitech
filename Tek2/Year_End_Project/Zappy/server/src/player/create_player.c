/*
** EPITECH PROJECT, 2020
** create_player.c
** File description:
** create_player
*/

#include "player.h"

player_t* new_player(player_t **list, client_t* client)
{
    player_t *new_val = malloc(sizeof(player_t));

    if (new_val == NULL)
        perror("Malloc player");
    new_val->uuid = strdup(client->uuid);
    new_val->alive = true;
    new_val->elevation = 1;
    new_val->view_direction = UP;
    new_val->team_name = NULL;
    new_val->current_tile = NULL;
    new_val->resources = NULL;
    new_val->next = (*list);
    (*list) = new_val;
    return (new_val);
}

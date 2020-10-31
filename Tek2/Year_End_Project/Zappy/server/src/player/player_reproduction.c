/*
** EPITECH PROJECT, 2020
** zappy [WSL: Ubuntu-18.04]
** File description:
** player_reproduction
*/

#include "zappy_server.h"

void player_reproduct(zappy_t *zappy, egg_t *egg)
{
    new_player(&zappy->players, egg->client);
}

bool spawn_egg(zappy_t *zappy, client_t *client)
{
    egg_t *egg = malloc(sizeof(egg_t));

    egg->client = client;
    if (egg->client->socket > 0)
        player_reproduct(zappy, egg);
    else {
        perror("Socket error");
        return (false);
    }
    return (true);
}
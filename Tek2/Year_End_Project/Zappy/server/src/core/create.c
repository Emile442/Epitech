/*
** EPITECH PROJECT, 2020
** zappy
** File description:
** Zappy Core Init
*/

#include "zappy_server.h"

zappy_t* zappy_create(char** av)
{
    zappy_t* zappy = malloc(sizeof(zappy_t));
    data_t *data = malloc(sizeof(data_t));

    zappy->data = data;
    zappy->data->port = 0;
    zappy->data->width = 0;
    zappy->data->height = 0;
    zappy->data->optIndex = 0;
    zappy->teams = NULL;
    if (loop_option(zappy, av) == 84)
        exit(84);
    zappy->network = network_create(zappy->data->port);
    zappy->maps = create_map(zappy->data->width, zappy->data->height);
    zappy->players = NULL;
    zappy->loop = true;
    return (zappy);
}

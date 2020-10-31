/*
** EPITECH PROJECT, 2020
** zappy
** File description:
** Zappy Core Destroy
*/

#include "zappy_server.h"

void zappy_destroy(zappy_t* zappy)
{
    free_map(zappy->maps);
    network_destroy(zappy->network);
    if (zappy != NULL)
        free(zappy);
}

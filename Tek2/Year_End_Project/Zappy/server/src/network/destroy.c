/*
** EPITECH PROJECT, 2020
** zappy
** File description:
** Server Destroy
*/

#include "zappy_server.h"
#include <stdlib.h>

void network_destroy(network_t* network)
{
    if (network != NULL) {
        clients_destroy(network->clients);
        free(network);
    }
}

/*
** EPITECH PROJECT, 2020
** zappy
** File description:
** Network Destroy
*/

#include "network.h"

void network_destroy(network_t* network)
{
    close(network->socket);
    free(network);
}

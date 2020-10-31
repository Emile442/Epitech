/*
** EPITECH PROJECT, 2020
** zappy
** File description:
** Network Init
*/

#include "zappy_server.h"

network_t* network_create(int port)
{
    network_t* network = malloc(sizeof(network_t));

    socket_init(&network->socket_params, port);
    clients_init(network);
    return (network);
}

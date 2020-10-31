/*
** EPITECH PROJECT, 2020
** zappy
** File description:
** Server Start
*/

#include "zappy_server.h"

int network_start(network_t* network)
{
    if (socket_start(network) == 84)
        return (84);
    if (socket_bind(network) == 84)
        return (84);
    if (socket_listen(network) == 84)
        return (84);
    return (0);
}

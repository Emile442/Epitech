/*
** EPITECH PROJECT, 2020
** zappy
** File description:
** Server Socket
*/

#include "zappy_server.h"

void socket_init(struct sockaddr_in *address, int port)
{
    address->sin_family = AF_INET;
    address->sin_addr.s_addr = INADDR_ANY;
    address->sin_port = htons(port);
}

int socket_start(network_t* network)
{
    int opt = true;

    if ((network->socket = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("socket failed");
        return (84);
    }
    if (setsockopt(network->socket, SOL_SOCKET, SO_REUSEADDR, (char *)&opt,
    sizeof(opt)) < 0) {
        perror("setsockopt");
        return (84);
    }
    return (0);
}

int socket_bind(network_t* network)
{
    if (bind(network->socket, (struct sockaddr *)&network->socket_params, \
    sizeof(network->socket_params)) < 0) {
        perror("bind failed");
        return (84);
    }
    return (0);
}

int socket_listen(network_t* network)
{
    if (listen(network->socket, 3) < 0) {
        perror("listen");
        return (84);
    }
    return (0);
}

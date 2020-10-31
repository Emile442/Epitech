/*
** EPITECH PROJECT, 2020
** zappy
** File description:
** Clients New
*/

#include "zappy_server.h"

bool clients_new(network_t* network, fd_set readfds)
{
    int socket;
    char* msg = "WELCOME\n";
    int addrlen = sizeof(network->socket_params);

    if (!(FD_ISSET(network->socket, &readfds)))
        return (false);
    if ((socket = accept(network->socket, \
    (struct sockaddr *)&network->socket_params, (socklen_t*)&addrlen)) < 0) {
        perror("accept");
        return (true);
    }
    printf("Client new\n");
    send(socket, msg, strlen(msg), 0);
    client_push(&network->clients, socket);
    return (false);
}

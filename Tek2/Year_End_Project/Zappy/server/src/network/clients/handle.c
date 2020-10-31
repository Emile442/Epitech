/*
** EPITECH PROJECT, 2020
** zappy
** File description:
** Clients Handle
*/

#include "zappy_server.h"

void clients_handle2(zappy_t* zappy, client_t* client, int sd)
{
    int read_i;
    char buffer[1025];
    network_t* network = zappy->network;
    int addrlen = sizeof(network->socket_params);

    if ((read_i = read(sd , buffer, 1024)) == 0) {
        getpeername(sd, (struct sockaddr*)&network->socket_params, \
        (socklen_t*)&addrlen);
        printf("Client quit\n");
        close(sd);
        client->socket = 0;
    } else {
        buffer[read_i] = '\0';
        zappy_disptach(zappy, client, buffer);
    }
}

void clients_handle(zappy_t* zappy, int sd, fd_set readfds)
{
    network_t* network = zappy->network;

    for (client_t *client = network->clients; client; client = client->next) {
        sd = client->socket;
        if (FD_ISSET(sd, &readfds)) {
            clients_handle2(zappy, client, sd);
        }
    }
}

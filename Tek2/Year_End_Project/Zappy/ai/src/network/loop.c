/*
** EPITECH PROJECT, 2020
** zappy
** File description:
** Network Loop
*/

#include "zappy_ai.h"

void network_loop(zappy_t* zappy)
{
    int v = 1;
    network_t* net = zappy->network;
    fd_t fds = net->fds;

    memset(net->buff_send, '\0', 255);
    while (zappy->loop) {
        network_setup_fd(net->socket, &fds);
        v = select(net->socket + 1, &fds.read, &fds.write, &fds.except, NULL);
        if (v <= 0)
            zappy->loop = false;
        network_bind(zappy, net->socket, &fds);
        zappy_loop(zappy);
    }
}

/*
** EPITECH PROJECT, 2020
** zappy
** File description:
** Network Bind
*/

#include "zappy_ai.h"

void network_bind(zappy_t* zappy, int socket, fd_t* fds)
{
    if (FD_ISSET(socket, &fds->write))
        network_send(zappy->network, zappy->network->buff_send);
    if (FD_ISSET(socket, &fds->read))
        network_recv(zappy);
    if (FD_ISSET(STDIN_FILENO, &fds->except)
    || FD_ISSET(socket, &fds->except)) {
        exit(EXIT_FAILURE);
    }
}

/*
** EPITECH PROJECT, 2020
** zappy
** File description:
** Network Reveive
*/

#include "zappy_ai.h"

void network_recv(zappy_t* zappy)
{
    char buffer[255];

    memset(buffer, '\0', 255);
    recv(zappy->network->socket, buffer, sizeof(buffer), 0);
    if (strlen(buffer) == 0) {
        zappy->loop = false;
        return;
    }
    zappy_disptach_recv(zappy, buffer);
}

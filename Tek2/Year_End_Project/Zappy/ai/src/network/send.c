/*
** EPITECH PROJECT, 2020
** zappy
** File description:
** Network Send
*/

#include "zappy_ai.h"
#include "network.h"

void server_send(zappy_t* zappy, const char* str)
{
    memset(zappy->network->buff_send, '\0', 255);
    strcpy(zappy->network->buff_send, str);
}

void network_send(network_t* network, char* str)
{
    send(network->socket, str, strlen(str), 0);
    memset(str, '\0', 255);
}

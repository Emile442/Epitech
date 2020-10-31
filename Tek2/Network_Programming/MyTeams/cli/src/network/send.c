/*
** EPITECH PROJECT, 2020
** cli
** File description:
** send.cpp
*/

#include "my_teams.h"

void network_send(server_t* server, char* str)
{
    send(server->socket, str, strlen(str), 0);
    memset(str, '\0', 255);
}

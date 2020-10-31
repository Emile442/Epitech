/*
** EPITECH PROJECT, 2020
** myteams_cli
** File description:
** recv.cpp
*/

#include "my_teams.h"

void network_recv(my_teams_t* teams)
{
    char buffer[255];

    recv(teams->server->socket, buffer, sizeof(buffer), 0);
    server_dispatch(teams, buffer);
}
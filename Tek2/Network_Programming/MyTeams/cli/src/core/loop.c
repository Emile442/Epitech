/*
** EPITECH PROJECT, 2020
** cli
** File description:
** loop
*/

#include "my_teams.h"

void core_loop(my_teams_t* teams)
{
    int v = 1;
    server_t* srv = teams->server;
    fd_t fds = srv->fds;

    teams->buffer->send = malloc(255 * sizeof(char));
    teams->buffer->local = malloc(255 * sizeof(char));
    memset(teams->buffer->send, '\0', 255);
    memset(teams->buffer->local, '\0', 255);
    while (teams->loop) {
        network_setup_fd(srv->socket, &fds);
        v = select(srv->socket + 1, &fds.read, &fds.write, &fds.except, NULL);
        if (v <= 0)
            teams->loop = false;
        network_bind(teams, srv->socket, &fds);
    }
}
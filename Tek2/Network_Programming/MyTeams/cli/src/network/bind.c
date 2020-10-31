/*
** EPITECH PROJECT, 2020
** cli
** File description:
** bind
*/

#include "my_teams.h"

void network_bind(my_teams_t* teams, int socket, fd_t* fds)
{
    if (FD_ISSET(STDIN_FILENO, &fds->read))
        core_prompt(teams);

    if (FD_ISSET(socket, &fds->write))
        network_send(teams->server, teams->buffer->send);

    if (FD_ISSET(socket, &fds->read))
        network_recv(teams);

    if (FD_ISSET(STDIN_FILENO, &fds->except)
    || FD_ISSET(socket, &fds->except)) {
        exit(EXIT_FAILURE);
    }
}

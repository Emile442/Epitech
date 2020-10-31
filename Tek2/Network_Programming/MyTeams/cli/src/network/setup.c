/*
** EPITECH PROJECT, 2020
** cli
** File description:
** setup
*/

#include "my_teams.h"

void network_setup_fd(int socket, fd_t* fds)
{
    FD_ZERO(&fds->read);
    FD_SET(STDIN_FILENO, &fds->read);
    FD_SET(socket, &fds->read);

    FD_ZERO(&fds->write);
    FD_SET(socket, &fds->write);

    FD_ZERO(&fds->except);
    FD_SET(STDIN_FILENO, &fds->except);
    FD_SET(socket, &fds->except);
}
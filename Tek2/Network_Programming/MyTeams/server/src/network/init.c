/*
** EPITECH PROJECT, 2020
** MyTeams
** File description:
** init
*/

#include "my_teams.h"

void newtork_init(my_teams_t* teams, int port)
{
    init_client_socket(&teams->clients);
    socket_type(&teams->address, port);
}

int create_server_socket(server_t *server)
{
    int opt = true;

    if ((server->socket = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("socket failed");
        return (84);
    }
    if (setsockopt(server->socket, SOL_SOCKET, SO_REUSEADDR, (char *)&opt,
    sizeof(opt)) < 0) {
        perror("setsockopt");
        return (84);
    }
    return (0);
}

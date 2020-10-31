/*
** EPITECH PROJECT, 2020
** MyTeams
** File description:
** server
*/

#include "my_teams.h"

int bind_socket(struct sockaddr_in address, server_t *server)
{
    if (bind(server->socket, (struct sockaddr *)&address, sizeof(address))<0) {
        perror("bind failed");
        return (84);
    }
    return (0);
}

void socket_type(struct sockaddr_in *address, int port)
{
    address->sin_family = AF_INET;
    address->sin_addr.s_addr = INADDR_ANY;
    address->sin_port = htons(port);
}

int listen_socket(server_t *server)
{
    if (listen(server->socket, 3) < 0) {
        perror("listen");
        return (84);
    }
    return (0);
}

int connections(my_teams_t* teams)
{
    int sd;
    int max_sd;
    fd_set readfds;
    int addrlen = sizeof(teams->address);

    while (true) {
        FD_ZERO(&readfds);
        max_sd = (&teams->server)->socket;
        FD_SET(max_sd, &readfds);
        for (int i = 0; i < (&teams->clients)->max_clients; i++) {
            sd = (&teams->clients)->client[i].socket;
            (sd > 0) ? FD_SET(sd, &readfds) : NULL;
            max_sd = (sd > max_sd) ? sd : max_sd;
        }
        if ((select(max_sd + 1, &readfds, NULL, NULL, NULL) < 0) \
            && (errno != EINTR))
            printf("select error");
        if (new_client(teams, addrlen, readfds))
            exit(84);
        handle_client(teams, addrlen, sd, readfds);
    }
}

int launch_server(struct sockaddr_in address, server_t *server)
{
    if (create_server_socket(server) == 84)
        return (84);
    if (bind_socket(address, server) == 84)
        return (84);
    if (listen_socket(server) == 84)
        return (84);
    return (0);
}

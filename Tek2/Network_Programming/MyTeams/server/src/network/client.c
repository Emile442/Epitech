/*
** EPITECH PROJECT, 2020
** server
** File description:
** client
*/

#include "my_teams.h"

void init_client_socket(network_t *clients)
{
    clients->max_clients = 30;
    for (int i = 0; i < clients->max_clients; i++) {
        clients->client[i].socket = 0;
        clients->client[i].uuid = NULL;
    }
}

static bool is_valid_entry(const char* str)
{
    int n_params = 0;

    for (int i = 0; str[i]; i++) {
        if (!(isalnum(str[i]) || str[i] == '"' || str[i] == ' ' || \
            str[i] == '-' || str[i] == '\r' || str[i] == '\n'))
            return (false);
        if (str[i] == '"')
            n_params++;
    }
    if (n_params == 0)
        return (true);
    return ((n_params % 2) == 0);
}

bool new_client(my_teams_t* teams, int addrlen, fd_set readfds)
{
    int socket;
    char* msg = "200 MyTeams\r\n";
    server_t* server = &teams->server;
    network_t* clients = &teams->clients;

    if (!(FD_ISSET(server->socket, &readfds)))
        return (false);
    if ((socket = accept(server->socket, \
    (struct sockaddr *)&teams->address, (socklen_t*)&addrlen)) < 0) {
        perror("accept");
        return (true);
    }
    printf("Client new\n");
    send(socket, msg, strlen(msg), 0);
    for (int i = 0; i < clients->max_clients; i++) {
        if (clients->client[i].socket == 0) {
            clients->client[i].socket = socket;
            break;
        }
    }
    return (false);
}

void handle_client2(my_teams_t* teams, int addrlen, int sd, int i)
{
    int read_i;
    char buffer[1025];
    network_t* clients = &teams->clients;

    if ((read_i = read(sd , buffer, 1024)) == 0) {
        getpeername(sd, (struct sockaddr*)&teams->address, \
        (socklen_t*)&addrlen);
        printf("Client quit\n");
        close(sd);
        clients->client[i].socket = 0;
    } else {
        buffer[read_i] = '\0';
        if (is_valid_entry(buffer))
            dispatch_cmd(teams, &clients->client[i], buffer);
        else
            send_to(clients->client[i].socket, rfc_str(500, "Bad format"));
    }
}

void handle_client(my_teams_t* teams, int addrlen, int sd, fd_set readfds)
{

    network_t* clients = &teams->clients;

    for (int i = 0; i < clients->max_clients; i++) {
        sd = clients->client[i].socket;
        if (FD_ISSET(sd, &readfds)) {
            handle_client2(teams, addrlen, sd, i);
        }
    }
}

/*
** EPITECH PROJECT, 2020
** MyTeams
** File description:
** network
*/

#ifndef NETWORK_H_
#define NETWORK_H_

#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <sys/time.h>

typedef struct server_s {
    int socket;
} server_t;

typedef struct client_s {
    int socket;
    char* uuid;
} client_t;

typedef struct network_s {
    int max_clients;
    // int client_socket[30];
    client_t client[30];
} network_t;

void init_client_socket(network_t *clients);
int bind_socket(struct sockaddr_in address, server_t *server);
void socket_type(struct sockaddr_in *addressn, int port);
int listen_socket(server_t *server);
int launch_server(struct sockaddr_in address, server_t *server);
void client_socket(fd_set readfds, network_t *clients, server_t *server);


#endif /* !NETWORK_H_ */

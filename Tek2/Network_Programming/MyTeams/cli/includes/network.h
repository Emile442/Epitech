/*
** EPITECH PROJECT, 2020
** MyTeams
** File description:
** network
*/

#ifndef NETWORK_H_
#define NETWORK_H_

#include <netdb.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <zconf.h>
#include <arpa/inet.h>

typedef struct fd_s {
    fd_set read;
    fd_set write;
    fd_set except;
} fd_t;

typedef struct server_s {
    int socket;
    struct sockaddr_in servaddr;
    fd_t fds;
} server_t;

void network_init(server_t* srv, const char* ip, int port);
void network_setup_fd(int socket, fd_t* fds);
void network_send(server_t* server, char* str);

#endif /* !NETWORK_H_ */

/*
** EPITECH PROJECT, 2020
** zappy
** File description:
** AI - Network
*/

#ifndef MY_NETWORK_H_
#define MY_NETWORK_H_

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

typedef struct network_s {
    int socket;
    struct sockaddr_in servaddr;
    fd_t fds;
    char* buff_send;
} network_t;

network_t* network_create(const char* ip, int port);
void network_destroy(network_t* network);
void network_setup_fd(int socket, fd_t* fds);
void network_send(network_t* network, char* str);

#endif /* !MY_NETWORK_H_ */

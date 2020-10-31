/*
** EPITECH PROJECT, 2020
** cli
** File description:
** init
*/

#include "my_teams.h"

void network_init(server_t* srv, const char* ip, int port)
{
    srv->socket = socket(AF_INET, SOCK_STREAM, 0);
    if (srv->socket == -1) {
        printf("socket creation failed...\n");
        exit(0);
    } else
        printf("Socket successfully created..\n");

    srv->servaddr.sin_family = AF_INET;
    srv->servaddr.sin_addr.s_addr = inet_addr(ip);
    srv->servaddr.sin_port = htons(port);

    if (connect(srv->socket, (struct sockaddr*)&srv->servaddr, \
    sizeof(srv->servaddr)) != 0) {
        printf("connection with the server failed...\n");
        exit(0);
    } else
        printf("connected to the server.\n");
}
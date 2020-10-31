/*
** EPITECH PROJECT, 2020
** zappy
** File description:
** Network Init
*/


#include "network.h"

network_t* network_create(const char* ip, int port)
{
    network_t* network = malloc(sizeof(network_t));

    network->socket = socket(AF_INET, SOCK_STREAM, 0);
    if (network->socket == -1) {
        perror("socket creation failed...");
        exit(0);
    }
    network->servaddr.sin_family = AF_INET;
    network->servaddr.sin_addr.s_addr = inet_addr(ip);
    network->servaddr.sin_port = htons(port);
    if (connect(network->socket, (struct sockaddr*)&network->servaddr, \
    sizeof(network->servaddr)) != 0) {
        perror("connection with the server failed...");
        exit(0);
    }
    network->buff_send = malloc(255 * sizeof(char));
    return (network);
}

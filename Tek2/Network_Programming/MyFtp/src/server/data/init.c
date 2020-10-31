/*
** EPITECH PROJECT, 2020
** MyFtp
** File description:
** data/init.c
*/

#include "ftp.h"

struct sockaddr_in data_init_socket(int port)
{
    struct sockaddr_in server;

    server.sin_family = AF_INET;
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_port = htons(port);
    return (server);
}

int data_init_fd(data_t* data, struct sockaddr_in s_socket)
{
    int fd = 0;

    if ((fd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
        exit_with_error("ERROR Data Socket");

    while (bind(fd, (const struct sockaddr *) &s_socket, \
    sizeof(s_socket)) < 0) {
        data->port = htons(rdm_number(49152, 65535));
        data->socket_params.sin_port = data->port;
    }
    listen(fd, 10);
    return (fd);
}

data_t* data_init(char* ip, int port, mode_t mode)
{
    data_t* data = malloc(sizeof(data_t));

    if (mode == ACTIVE) {
        data->port = port;
        data->ip = strdup(ip);
        return (data);
    }
    data->ip = NULL;
    data->port = port;
    data->socket_params = data_init_socket(data->port);
    data->fd = data_init_fd(data, data->socket_params);
    return (data);
}

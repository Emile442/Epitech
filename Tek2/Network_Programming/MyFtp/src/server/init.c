/*
** EPITECH PROJECT, 2020
** MyFtp
** File description:
** server/init
*/

#include "ftp.h"

struct sockaddr_in server_init_socket(int port)
{
    struct sockaddr_in server;

    server.sin_family = AF_INET;
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_port = htons(port);
    return (server);
}

int server_init_fd(struct sockaddr_in s_socket)
{
    int fd = 0;

    if ((fd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
        exit_with_error("ERROR socket");
    if (bind(fd, (const struct sockaddr *) &s_socket, sizeof(s_socket)) < 0)
        exit_with_error("ERROR bind");
    listen(fd, 10);
    return (fd);
}

server_t* server_init(int port, const char* path)
{
    server_t* server = malloc(sizeof(server_t));
    int opt = 1;

    server->exit = false;
    server->socket_params = server_init_socket(port);
    server->fd = server_init_fd(server->socket_params);
    setsockopt(server->fd, SOL_SOCKET, SO_REUSEADDR, (char *)&opt, sizeof(opt));
    server->path = realpath(path, NULL);
    return (server);
}

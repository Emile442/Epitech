/*
** EPITECH PROJECT, 2020
** MyFtp
** File description:
** server/client/init
*/

#include "ftp.h"

void on_new_connection(int fd)
{
    printf("[FTP SERVER][CLIENT %d]: connected\n", fd);
}

client_t* client_init(server_t* server)
{
    client_t* client = malloc(sizeof(client_t));
    unsigned int clientLen = sizeof(client->socket_params);

    client->exit = false;
    client->username = NULL;
    client->auth = false;
    client->path = strdup(server->path);
    client->data = NULL;
    client->ftp_mode = DEFAULT;
    if ((client->fd = accept(server->fd, \
        (struct sockaddr *) &client->socket_params, &clientLen)) < 0)
        exit_with_error("ERROR accept");
    on_new_connection(client->fd);
    if ((client->pid = fork()) < 0)
        exit_with_error("ERROR fork");
    return (client);
}

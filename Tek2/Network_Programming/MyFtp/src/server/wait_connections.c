/*
** EPITECH PROJECT, 2020
** MyFtp
** File description:
** server/wait_connection
*/

#include "ftp.h"

void server_wait_connection(server_t* server)
{
    client_t* client = client_init(server);

    if (client->pid == 0) {
        close(server->fd);
        ftp_response(client, "Service ready for new user.", "220");
        while (!client->exit) {
            new_client(client);
        }
        printf("[FTP SERVER][CLIENT %d]: disconnected\n", client->fd);
        exit(0);
    } else {
        close(client->fd);
    }
}

/*
** EPITECH PROJECT, 2020
** MyFtp
** File description:
** client/new
*/

#include "ftp.h"

void new_client(client_t* client)
{
    int n;
    char* buffer = malloc(sizeof(char) * 255);

    memset(buffer, '\0', 255);
    if ((n = read(client->fd, buffer, 255)) < 0)
        exit_with_error("ERROR read");
    if (strstr(buffer, "\n") != NULL) {
        dispatch_cmd(client, buffer);
    } else {
        client->exit = true;
    }
}

/*
** EPITECH PROJECT, 2020
** MyFtp
** File description:
** commands/quit
*/

#include "ftp.h"

void command_quit(client_t* client, char** cmd)
{
    (void)cmd;
    ftp_response(client, "Service closing control connection.", "221");
    if (client->path)
        free(client->path);
    if (client->username)
        free(client->username);
    client->exit = true;
}

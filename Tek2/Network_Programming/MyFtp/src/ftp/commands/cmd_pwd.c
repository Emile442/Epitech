/*
** EPITECH PROJECT, 2020
** MyFtp
** File description:
** cmd_pwd
*/

#include "ftp.h"

void cmd_pwd(client_t* client, char** cmd)
{
    char* tmp = malloc(sizeof(char) * (strlen(client->path) + 3));

    (void) cmd;
    strcat(tmp, "\"");
    strcat(tmp, client->path);
    strcat(tmp, "\"");
    ftp_response(client, tmp, "257");
}

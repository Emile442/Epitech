/*
** EPITECH PROJECT, 2020
** MyFtp
** File description:
** cmd_pwd
*/

#include "ftp.h"

void cmd_cdup(client_t* client, char** cmd)
{
    char * new_path = realpath("../", NULL);

    (void) cmd;
    if (new_path == NULL) {
        ftp_response(client, "Failed to change directory.", "550");
        return;
    }
    chdir(new_path);
    if (client->path)
        free(client->path);
    client->path = strdup(new_path);
    ftp_response(client, "Directory successfully changed.", "250");
}

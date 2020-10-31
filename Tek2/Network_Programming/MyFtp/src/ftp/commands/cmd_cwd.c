/*
** EPITECH PROJECT, 2020
** MyFtp
** File description:
** cmd_pwd
*/

#include "ftp.h"

void cmd_cwd(client_t* client, char** cmd)
{
    char * new_path;

    if (strlen_array(cmd) != 2) {
        ftp_response(client, "Please give just 1 argument", "550");
        return;
    }
    if ((new_path = realpath(cmd[1], NULL)) == NULL) {
        ftp_response(client, "Failed to change directory.", "550");
        return;
    }
    chdir(new_path);
    if (client->path)
        free(client->path);
    client->path = strdup(new_path);
    ftp_response(client, "Directory successfully changed.", "250");
}

/*
** EPITECH PROJECT, 2020
** MyFtp
** File description:
** Middleware Data
*/

#include "ftp.h"

bool data_middleware(client_t* client, char** cmd)
{
    if ((strcmp("LIST", cmd[0]) == 0 || strcmp("RETR", cmd[0]) == 0 ||
    strcmp("STOR", cmd[0]) == 0) && client->data == NULL) {
        ftp_response(client, "Use PORT or PASV first.", "425");
        return (false);
    }
    return (true);
}

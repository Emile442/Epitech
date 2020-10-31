/*
** EPITECH PROJECT, 2020
** MyFtp
** File description:
** Auth Middleware
*/

#include "ftp.h"

bool auth_middleware(client_t* client, char** cmd)
{
    if ((strcmp("QUIT", cmd[0]) != 0 && strcmp("USER", cmd[0]) != 0 \
    && strcmp("PASS", cmd[0]) != 0) && !client->auth) {
        ftp_response(client, "Please login with USER and PASS.", "530");
        return (false);
    }
    return (true);
}

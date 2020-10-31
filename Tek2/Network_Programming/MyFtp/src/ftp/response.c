/*
** EPITECH PROJECT, 2020
** MyFtp
** File description:
** reponse
*/

#include "ftp.h"

void ftp_response(client_t* client, const char* str, const char* code)
{
    int n = dprintf(client->fd, "%s %s\n", code, str);

    if (n < 0)
        exit_with_error("ERROR send");
    printf("\033[0;33m[FTP SERVER][CLIENT %d][SEND]: {%s} %s\033[0m\r\n", \
    client->fd, code, str);
}

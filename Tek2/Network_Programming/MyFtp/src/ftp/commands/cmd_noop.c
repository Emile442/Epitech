/*
** EPITECH PROJECT, 2020
** MyFtp
** File description:
** Noop
*/

#include "ftp.h"

void cmd_noop(client_t* client, char** cmd)
{
    (void) cmd;
    ftp_response(client, "NOOP ok.", "200");
}

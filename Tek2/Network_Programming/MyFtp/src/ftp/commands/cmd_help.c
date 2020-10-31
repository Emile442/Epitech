/*
** EPITECH PROJECT, 2020
** MyFtp
** File description:
** HELP
*/

#include "ftp.h"

void cmd_help(client_t* client, char** cmd)
{
    (void) cmd;
    ftp_response(client, "HELP USER PASS", "214");
}

/*
** EPITECH PROJECT, 2020
** MyFtp
** File description:
** LIST
*/

#include "ftp.h"

void cmd_list(client_t* client, char** cmd)
{
    (void) cmd;
    ftp_response(client, "HELP USER PASS", "214");
}

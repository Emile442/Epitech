/*
** EPITECH PROJECT, 2020
** MyFtp
** File description:
** command/pasv
*/

#include "ftp.h"

void cmd_pasv(client_t* client, char** cmd)
{
    char** tip = parse_str(inet_ntoa(client->socket_params.sin_addr), '.');
    char *res = malloc(sizeof(char) * 100);

    (void) cmd;
    client->data = data_init(NULL, 2424, PASV);
    client->data->ip = malloc(sizeof(char) * 17);
    sprintf(client->data->ip, "%s,%s,%s,%s", tip[0], tip[1], tip[2], tip[3]);
    client->ftp_mode = PASV;

    sprintf(res, "Entering Passive Mode (%s,%d,%d)", client->data->ip, \
    client->data->port / 256, client->data->port % 256);
    ftp_response(client, res, "227");
}

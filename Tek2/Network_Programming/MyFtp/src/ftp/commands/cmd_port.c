/*
** EPITECH PROJECT, 2020
** MyFtp
** File description:
** port
*/

#include "ftp.h"

void cmd_port(client_t* client, char** cmd)
{
    char** i_ip = parse_str(cmd[1], ',');
    char* ip = malloc(sizeof(char) * 17);

    if (strlen_array(cmd) != 2 || strlen_array(i_ip) != 6) {
        ftp_response(client, "Please put correct arg 'ip1,ip3,ip3,ip4,p1,p2'", \
        "500");
        return;
    }
    sprintf(ip, "%s.%s.%s.%s", i_ip[0], i_ip[1], i_ip[2], i_ip[3]);
    client->ftp_mode = ACTIVE;
    client->data = data_init(ip, atoi(i_ip[4]) * 256 + atoi(i_ip[5]), ACTIVE);
    printf("\033[0;34mPORT ENABLE: %s:%d\033[0m\n", client->data->ip, \
    client->data->port);
    ftp_response(client, "Active Mode: OK", "200");
    free(ip);
}

// PORT 0,10,0,0,23,23

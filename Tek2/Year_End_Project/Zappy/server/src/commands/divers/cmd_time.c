/*
** EPITECH PROJECT, 2020
** zappy
** File description:
** Cmd Test Time
*/

#include "zappy_server.h"

void cmd_time(zappy_t * zappy, client_t* client, char** command)
{
    (void) zappy;
    (void) command;
    for (double i = 0; i < 10000000; i++);
    send_to(client->socket, format_str("Hello world"));
}

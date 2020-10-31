/*
** EPITECH PROJECT, 2020
** zappy
** File description:
** Command - Ping
*/

#include "zappy_server.h"

void cmd_ping(zappy_t * zappy, client_t* client, char** command)
{
    (void) zappy;
    (void) command;
    send_to(client->socket, format_str("Pong"));
}

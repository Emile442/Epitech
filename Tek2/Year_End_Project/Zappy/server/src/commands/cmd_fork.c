/*
** EPITECH PROJECT, 2020
** zappy [WSL: Ubuntu-18.04]
** File description:
** cmd_fork
*/

#include "zappy_server.h"
#include "player.h"

void cmd_fork(zappy_t *zappy, client_t *client, char **command)
{
    (void)command;
    wait_time(zappy, 42);
    if (spawn_egg(zappy, client) == false)
        send_to(client->socket, format_str("ko"));
    send_to(client->socket, format_str("ok"));
}

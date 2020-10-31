/*
** EPITECH PROJECT, 2023
** zappy
** File description:
** cmd_all.c
*/

#include "zappy_server.h"

void cmd_broadcast_bis(zappy_t * zappy, client_t* client, char* str)
{
    for (client_t *cus = zappy->network->clients; cus; cus = cus->next) {
        if (cus->uuid == client->uuid)
            continue;
        str[8] = 48 + get_tile_direction(cus->player->current_tile, \
        client->player->current_tile);
        send_to(cus->socket, format_str(str));
    }
    if (str)
        free(str);
    wait_time(zappy, 7);
    send_to(client->socket, format_str("ok"));
}

void cmd_broadcast(zappy_t * zappy, client_t* client, char** command)
{
    char* str;
    int len = 0 + strlen("message 4, ");
    int i = 1;

    for (; command[i]; i++)
        len += strlen(command[i]);
    str = calloc(len + i + 1, sizeof(char));
    strcat(str, "message 0, ");
    for (int j = 1; command[j]; j++) {
        strcat(str, command[j]);
        if (command[j + 1])
            strcat(str, " ");
    }
    cmd_broadcast_bis(zappy, client, str);
}

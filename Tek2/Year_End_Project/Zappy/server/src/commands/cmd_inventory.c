/*
** EPITECH PROJECT, 2023
** zappy
** File description:
** cmd_inventory.c
*/

#include "zappy_server.h"

int get_resource_count(player_t *player, enum RESOURCE_TYPE type)
{
    int count = 0;

    for (resource_t *res = player->resources; res; res = res->next)
        if (res->resource_type == type)
            count++;
    return (count);
}

void cmd_inventory(zappy_t * zappy, client_t* client, char** command)
{
    (void) zappy;
    (void) command;
    player_t *p = client->player;
    char buffer[256];
    char *buff = buffer;

    wait_time(zappy, 1);
    if (p == NULL)
        return;
    buff += sprintf(buff, "[");
    for (enum RESOURCE_TYPE type = FOOD; type != NONE; type++) {
        buff += sprintf(buff, "%s %i", get_resource_name(type), \
        get_resource_count(p, type));
        if (type + 1 != NONE)
            buff += sprintf(buff, ", ");
    }
    buff += sprintf(buff, "]");
    send_to(client->socket, format_str(buffer));
}

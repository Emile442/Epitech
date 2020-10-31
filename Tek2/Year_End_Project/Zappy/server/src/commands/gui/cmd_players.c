/*
** EPITECH PROJECT, 2020
** zappy
** File description:
** gui players
*/

#include <math.h>
#include "zappy_server.h"

int player_str_len(player_t* pl)
{
    map_tile_t* tile = pl->current_tile;
    int x = tile->pos_x == 0 ? 1 : floor(log10(abs(tile->pos_x))) + 1;
    int y = tile->pos_y == 0 ? 1 : floor(log10(abs(tile->pos_y))) + 1;

    return (strlen(pl->team_name) + x + y + 3);
}

char* player_str(player_t* pl)
{
    map_tile_t* tile = pl->current_tile;
    char* str = calloc(player_str_len(pl) + 1, sizeof(char));

    sprintf(str, "%s:%d,%d", pl->team_name, tile->pos_x, tile->pos_y);
    return (str);
}

void cmd_gui_players(zappy_t * zappy, client_t* client, char** command)
{
    int len = 1;
    char* str;

    (void)command;
    for (client_t* cl = zappy->network->clients; cl; cl = cl->next)
        if (cl->player)
            len += player_str_len(cl->player) + 1;
    if (len == 1)
        return (send_to(client->socket, ""));
    str = calloc(len, sizeof(char));
    for (client_t* cl = zappy->network->clients; cl; cl = cl->next) {
        if (cl->player)
            strcat(str, player_str(cl->player));
        if (cl->player && cl->next)
            strcat(str, ";");
    }
    send_to(client->socket, format_str(str));
}

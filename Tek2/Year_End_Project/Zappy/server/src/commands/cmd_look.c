/*
** EPITECH PROJECT, 2020
** zappy
** File description:
** cmd_look
*/

#include "zappy_server.h"

map_tile_t *get_next_corner(player_t *player, map_tile_t *line_begin)
{
    switch (player->view_direction) {
    case UP:
        return (line_begin->up->left);
    case LEFT:
        return (line_begin->left->up);
    case DOWN:
        return (line_begin->down->left);
    case RIGHT:
        return (line_begin->right->up);
    }
    return (line_begin);
}

map_tile_t *get_next_tile(player_t *player, map_tile_t *curr)
{
    if (player->view_direction == UP || player->view_direction == DOWN)
        return (curr->right);
    return (curr->down);
}

int cmd_look_len(client_t* client)
{
    map_tile_t *curr = client->player->current_tile;
    map_tile_t *line_begin = curr;
    int len = 4;

    for (int i = 0, j = 1; i < 3 + client->player->elevation; i++, j += 2) {
        line_begin = get_next_corner(client->player, line_begin);
        curr = line_begin;
        for (int k = 0; k < j; k++) {
            len += tile_inventory_str_len(curr) + 1;
            curr = get_next_tile(client->player, curr);
        }
    }
    return (len);
}

void cmd_look(zappy_t * zappy, client_t* client, char** command)
{
    (void) zappy;
    (void) command;
    map_tile_t *curr = client->player->current_tile;
    map_tile_t *line_begin = curr;
    int len = cmd_look_len(client);
    char* str = calloc(len + 1, sizeof(char));

    wait_time(zappy, 7);
    strcat(str, "[");
    for (int i = 0, j = 1; i < 3 + client->player->elevation; i++, j += 2) {
        line_begin = get_next_corner(client->player, line_begin);
        curr = line_begin;
        for (int k = 0; k < j; k++) {
            strcat(str, tile_inventory_str(curr));
            strcat(str, ",");
            curr = get_next_tile(client->player, curr);
        }
    }
    str[strlen(str) - 1] = 0;
    strcat(str, "]");
    send_to(client->socket, format_str(str));
}

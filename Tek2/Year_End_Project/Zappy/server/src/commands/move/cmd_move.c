/*
** EPITECH PROJECT, 2023
** zappy
** File description:
** cmd_move.c
*/

#include "zappy_server.h"

void cmd_forward(zappy_t * zappy, client_t* client, char** command)
{
    (void) zappy;
    (void) command;
    player_t *p = client->player;
    map_tile_t* todo;

    if (p == NULL)
        return;
    wait_time(zappy, 7);
    if (p->view_direction == UP)
        todo = p->current_tile->up;
    if (p->view_direction == LEFT)
        todo = p->current_tile->left;
    if (p->view_direction == DOWN)
        todo = p->current_tile->down;
    if (p->view_direction == RIGHT)
        todo = p->current_tile->right;
    p->current_tile = todo;
    send_to(client->socket, format_str("ok"));
}

void cmd_right(zappy_t * zappy, client_t* client, char** command)
{
    (void) zappy;
    (void) command;
    player_t *p = client->player;
    int todo;

    if (p == NULL)
        return;
    wait_time(zappy, 7);
    todo = (p->view_direction == UP) ? RIGHT : p->view_direction - 1;
    p->view_direction = todo;
    send_to(client->socket, format_str("ok"));
}

void cmd_left(zappy_t * zappy, client_t* client, char** command)
{
    (void) zappy;
    (void) command;
    player_t *p = client->player;
    int todo;

    if (p == NULL)
        return;
    wait_time(zappy, 7);
    todo = (p->view_direction == RIGHT) ? UP : p->view_direction + 1;
    p->view_direction = todo;
    send_to(client->socket, format_str("ok"));
}

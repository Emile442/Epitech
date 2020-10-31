/*
** EPITECH PROJECT, 2020
** dir_move.c
** File description:
** dir_move
*/

#include "zappy_ai.h"

void go_right(zappy_t *zappy)
{
    server_send(zappy, (format_str("Forward")));
    server_send(zappy, (format_str("Right")));
}

void go_left(zappy_t *zappy)
{
    server_send(zappy, (format_str("Forward")));
    server_send(zappy, (format_str("Left")));
}

void go_forward(zappy_t *zappy)
{
    server_send(zappy, (format_str("Forward")));
}
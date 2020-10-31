/*
** EPITECH PROJECT, 2020
** zappy
** File description:
** cmd_register
*/

#include "zappy_ai.h"

void cmd_register(zappy_t* zappy, char** command)
{
    (void) command;
    zappy->state = 1;
    return (server_send(zappy, format_str(zappy->team)));
}

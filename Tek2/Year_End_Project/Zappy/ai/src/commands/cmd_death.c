/*
** EPITECH PROJECT, 2020
** zappy
** File description:
** cmd_death
*/

#include "zappy_ai.h"

void cmd_death(zappy_t* zappy, char** command)
{
    (void) command;
    zappy->loop = false;
}

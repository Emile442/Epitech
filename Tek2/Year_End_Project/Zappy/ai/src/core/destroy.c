/*
** EPITECH PROJECT, 2020
** zappy
** File description:
** Core Destroy
*/

#include "zappy_ai.h"

void zappy_destroy(zappy_t* zappy)
{
    network_destroy(zappy->network);
    free(zappy);
}

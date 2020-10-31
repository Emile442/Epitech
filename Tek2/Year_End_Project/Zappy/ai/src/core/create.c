/*
** EPITECH PROJECT, 2020
** zappy
** File description:
** Core Init
*/

#include "zappy_ai.h"

zappy_t* zappy_create(int ac, char **av)
{
    zappy_t* zappy = malloc(sizeof(zappy_t));

    zappy->port = 0;
    zappy->state = 0;
    zappy->team = NULL;
    zappy->machine = strdup("127.0.0.1");
    zappy->loop = true;
    zappy->height = 0;
    zappy->height = 0;
    if (check_option(ac, av, zappy) == 84)
        exit(84);
    zappy->network = network_create(zappy->machine, zappy->port);
    return (zappy);
}

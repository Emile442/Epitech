/*
** EPITECH PROJECT, 2020
** zappy
** File description:
** main
*/

#include "zappy_server.h"
#include <signal.h>
#include <stdio.h>

int main(int ac, char **av)
{
    zappy_t* zappy = zappy_create(av);

    if (ac == 1)
        return (84);
    if (network_start(zappy->network) == 84)
        return (84);
    printf("Zappy server running on port %d\n", zappy->data->port);
    printf("Maps size [%d, %d] and frequence set to %d\n", \
    zappy->data->height, zappy->data->width, 100);
    if (zappy->maps == NULL) {
        printf("Error creating map...\n");
        return (84);
    }
    if (network_loop(zappy) == 84)
        return (84);
    zappy_destroy(zappy);
    return (0);
}

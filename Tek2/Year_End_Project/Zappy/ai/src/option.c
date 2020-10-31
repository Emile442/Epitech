/*
** EPITECH PROJECT, 2020
** zappy
** File description:
** cmd_move.c
*/

#include "zappy_ai.h"

int fill_port(zappy_t *zappy, char *optarg)
{
    if (atoi(optarg) <= 0) {
        fprintf(stderr, "Please enter a correct port\n");
        exit(84);
    }
    zappy->port = atoi(optarg);
    return (0);
}

int check_option(int ac, char **av, zappy_t *zappy)
{
    int opt;

    while ((opt = getopt(ac, av, "p:n:h:")) != -1) {
        switch (opt) {
        case 112:
            fill_port(zappy, optarg);
            break;
        case 110:
            zappy->team = optarg;
            break;
        case 104:
            zappy->machine = optarg;
            break;
        default:
            exit(84);
            break;
        }
    }
    return ((!zappy->port || !zappy->team) ? 84 : 0);
}

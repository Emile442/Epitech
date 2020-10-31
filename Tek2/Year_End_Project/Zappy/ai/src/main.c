/*
** EPITECH PROJECT, 2020
** zappy
** File description:
** main
*/

#include "zappy_ai.h"

void print_help(void)
{
    printf("USAGE: ./zappy_ai -p port -n name -h machine\n\
    \tport\tis the port number\n\
    \tname\tis the name of the team\n\
    \tmachine\tis the of the machine; localhost by default\n");
}

int main(int ac, char **av)
{
    zappy_t* zappy;

    if (ac == 2 && strcmp(av[1], "-help") == 0) {
        print_help();
        return (0);
    }
    zappy = zappy_create(ac, av);
    network_loop(zappy);
    zappy_destroy(zappy);
    return (0);
}

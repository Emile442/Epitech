/*
** EPITECH PROJECT, 2019
** main
** File description:
** main for navy project
*/

#include "navy.h"
#include <stdlib.h>

int main(int ac, char **av)
{
    char **map;

    if (ac == 1 || !(map = get_map_from_file(av[ac - 1])))
        return (84);
    my_printf("my_pid: %i\n", getpid());
    define_signalhandler();
    if (ac == 2)
        return (run_server(map));
    for (int i = 0; av[1][i]; i++)
        if (av[1][i] < '0' || av[1][i] > '9')
            return (84);
    return (run_client(map, my_get_nbr(av[1])));
}

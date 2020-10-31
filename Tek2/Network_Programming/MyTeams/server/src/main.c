/*
** EPITECH PROJECT, 2020
** MyTeams
** File description:
** main
*/

#include "my_teams.h"

int main(const int ac , const char **av)
{
    my_teams_t* teams;

    if (has_error(ac, av))
        return (84);
    if (strcmp(av[1], "-help") == 0)
        exit(print_help());
    teams = malloc(sizeof(my_teams_t));
    newtork_init(teams, atoi(av[1]));
    if (launch_server(teams->address, &teams->server) == 84)
        return (84);
    printf("MyTeams lauched on port %d \n", atoi(av[1]));
    printf("Waiting for connections ...\n");
    if (connections(teams) == 84)
        return (84);
    free(teams);
    return 0;
}
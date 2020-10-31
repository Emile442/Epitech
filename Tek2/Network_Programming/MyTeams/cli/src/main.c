/*
** EPITECH PROJECT, 2020
** MyTeams
** File description:
** main
*/

#include "my_teams.h"

int main(int ac, char const **av)
{
    my_teams_t* teams;

    if (has_error(ac, av))
        return (84);
    teams = malloc(sizeof(my_teams_t));
    teams->buffer = malloc(sizeof(buffer_t));
    teams->loop = true;
    teams->server = malloc(sizeof(server_t));
    teams->user = malloc(sizeof(user_t));
    network_init(teams->server, av[1], atoi(av[2]));
    core_loop(teams);
    close(teams->server->socket);
    free(teams->server);
    free(teams);
    return 0;
}

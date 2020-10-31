/*
** EPITECH PROJECT, 2020
** zappy
** File description:
** Server Loop
*/

#include "zappy_server.h"

void check_dead_client_bis(zappy_t* zappy, client_t *cus)
{
    team_t* tm = NULL;

    if (cus->player) {
        tm = team_found_by_name(zappy->teams, cus->player->team_name);
        tm->max++;
    }
}

void check_dead_client(zappy_t* zappy)
{
    for (client_t *cus = zappy->network->clients; cus; cus = cus->next) {
        if (cus->socket == 0) {
            check_dead_client_bis(zappy, cus);
            client_remove(&zappy->network->clients, cus);
        }
    }
}

int network_loop(zappy_t* zappy)
{
    int sd;
    int max_sd;
    fd_set readfds;

    while (zappy->loop) {
        FD_ZERO(&readfds);
        max_sd = zappy->network->socket;
        FD_SET(max_sd, &readfds);
        check_dead_client(zappy);
        for (client_t *cus = zappy->network->clients; cus; cus = cus->next) {
            sd = cus->socket;
            (sd > 0) ? FD_SET(sd, &readfds) : NULL;
            max_sd = (sd > max_sd) ? sd : max_sd;
        }
        if (select(max_sd + 1, &readfds, NULL, NULL, NULL) < 0)
            perror("select error");
        if (clients_new(zappy->network, readfds))
            exit(84);
        clients_handle(zappy, sd, readfds);
    }
    return (0);
}

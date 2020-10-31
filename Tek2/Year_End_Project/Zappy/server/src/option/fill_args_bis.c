/*
** EPITECH PROJECT, 2020
** zappy
** File description:
** fill args bis
*/

#include "zappy_server.h"

int init_client(zappy_t *net, char **args, int i)
{
    net->data->nbclient = atoi(args[i]);

    if (net->data->nbclient <= 0){
        fprintf(stderr, "Please enter a valid number of client\n");
        return (84);
    }
    for (team_t *team = net->teams; team; team = team->next) {
        team->max = net->data->nbclient;
    }
    return (0);
}

int init_freq(zappy_t *net, char **args, int i)
{
    net->data->freq = atoi(args[i]);

    if (net->data->freq <= 0){
        fprintf(stderr, "Please enter a valid freq\n");
        return (84);
    }
    return (0);
}

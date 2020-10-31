/*
** EPITECH PROJECT, 2020
** zappy
** File description:
** fillargs
*/

#include "zappy_server.h"

int init_port(zappy_t *net, char **args, int i)
{
    net->data->port = atoi(args[i]);

    if (net->data->port <= 0){
        fprintf(stderr, "Please enter a valid port\n");
        return (84);
    }
    return (0);
}

int init_width(zappy_t *net, char **args, int i)
{
    net->data->width = atoi(args[i]);

    if (net->data->width < 10 || net->data->width > 30){
        fprintf(stderr, "Please enter a valid width between 10 and 30\n");
        return (84);
    }
    return (0);
}

int init_height(zappy_t *net, char **args, int i)
{
    net->data->height = atoi(args[i]);

    if (net->data->height < 10 || net->data->height > 30){
        fprintf(stderr, "Please enter a valid height between 10 and 30\n");
        return (84);
    }
    return (0);
}

int create_team(team_t **team, char **args, int j)
{
    team_t *new_team = malloc(sizeof(team_t));

    if (new_team == NULL)
        return (84);
    new_team->name = args[j];
    new_team->next = (*team);
    (*team) = new_team;
    return (0);
}

int init_teams(zappy_t *net, char **args, int i)
{
    int j = i - 1;

    while (args[++j] && args[j][0] != '-') {
        if (create_team(&net->teams, args, j) == 84){
            return (84);
        }
    }
    return (0);
}

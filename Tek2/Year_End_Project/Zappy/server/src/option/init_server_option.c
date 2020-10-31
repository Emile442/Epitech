/*
** EPITECH PROJECT, 2020
** zappy
** File description:
** Zappy Core Destroy
*/

#include "zappy_server.h"

const option_t op_l[] = {
    {"-p", init_port},
    {"-x", init_width},
    {"-y", init_height},
    {"-n", init_teams},
    {"-c", init_client},
    {"-f", init_freq},
    {"error", NULL},
    {NULL, NULL}
};

int check_option(zappy_t *net, char **args, int i)
{
    int rt = 0;
    while (op_l[++i].option) {
        if (strcmp(op_l[i].option, "error") == 0 \
            && args[net->data->optIndex][0] == '-')
            return (84);
        if (strcmp(args[net->data->optIndex], "-h") == 0 ||
        strcmp(args[net->data->optIndex], "--help") == 0) {
            puts(USAGE);
            exit(0);
        }
        if (strcmp(args[net->data->optIndex], op_l[i].option) == 0)
            rt = args[net->data->optIndex + 1] == NULL ? 84 : rt;
        if (rt == 84)
            return (rt);
        if (strcmp(args[net->data->optIndex], op_l[i].option) == 0)
            rt = op_l[i].fct(net, args, ++net->data->optIndex) == 84 ? 84 : rt;
        if (rt == 84)
            return (rt);
    }
    return (0);
}

bool has_error(zappy_t* zappy)
{
    bool rt = false;
    data_t* data = zappy->data;

    if (!data->height)
        printf("Please add height to run zappy server\n");
    if (!data->width)
        printf("Please add height to run zappy server\n");
    if (!data->nbclient)
        printf("Please add nbclient to run zappy server\n");
    if (!data->port)
        printf("Please add port to run zappy server\n");
    if (!data->height || !data->width || !data->nbclient || !data->port)
        rt = true;
    if (zappy->teams == NULL) {
        printf("Please add teams to run zappy server\n");
        rt = true;
    }
    return (rt);
}

int loop_option(zappy_t *net, char **args)
{
    int i = 0;

    while (args[++net->data->optIndex]) {
        i = -1;
        if (check_option(net, args, i) == 84) {
            printf("Invalid args\n");
            return (84);
        }
    }
    if (has_error(net))
        return (84);
    if (!net->data->freq)
        net->data->freq = 100;
    return (0);
}

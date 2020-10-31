/*
** EPITECH PROJECT, 2020
** zappy
** File description:
** cmd_team_register
*/

#include "zappy_server.h"

int do_team_register(zappy_t* zappy, client_t* client, team_t* team)
{
    char client_num[4];
    char map_size[20];

    if (team->max < 0)
        return (false);
    team->max--;
    sprintf(client_num, "%d", team->max);
    send_to(client->socket, format_str(client_num));
    sprintf(map_size, "%d %d", zappy->data->height, zappy->data->width);
    send_to(client->socket, format_str(map_size));
    client->player = new_player(&zappy->players, client);
    client->player->current_tile = random_spawn_position(zappy);
    client->player->team_name = strdup(team->name);
    return (true);
}

team_t* team_found_by_name(team_t* teams, char* str)
{
    for (team_t *tm = teams; tm; tm = tm->next) {
        if (strcmp(tm->name, str) == 0) {
            return (tm);
        }
    }
    return (NULL);
}

int cmd_team_register(zappy_t* zappy, client_t* client, char** parse_cmd)
{
    team_t* team = team_found_by_name(zappy->teams, parse_cmd[0]);

    if (team == NULL)
        return (false);
    return (do_team_register(zappy, client, team));
}

/*
** EPITECH PROJECT, 2020
** zappy
** File description:
** cmd_elevation.c
*/

#include "zappy_server.h"

const elevation_t elevation_list[] = {
    {1, check_elevation_one},
    {2, check_elevation_two},
    {3, check_elevation_three},
    {4, check_elevation_four},
    {5, check_elevation_five},
    {6, check_elevation_six},
    {7, check_elevation_seven},
    {0, NULL}
};

bool check_elevation_one(player_t *player)
{
    for (resource_t *item = player->resources; item; item = item->next) {
        if (item->resource_type == LINEMATE && item->amount >= 1)
            return (true);
    }
    return (false);
}

bool check_elevation_two(player_t *player)
{
    int condition = 0;

    for (resource_t *item = player->resources; item; item = item->next) {
        if (item->resource_type == LINEMATE && item->amount >= 1)
            condition++;
        if (item->resource_type == DERAUMERE && item->amount >= 1)
            condition++;
        if (item->resource_type == SIBUR && item->amount >= 1)
            condition++;
    }
    if (condition == 3)
        return true;
    return false;
}

bool check_elevation_three(player_t *player)
{
    int condition = 0;

    for (resource_t *item = player->resources; item; item = item->next) {
        if (item->resource_type == LINEMATE && item->amount >= 2)
            condition++;
        if (item->resource_type == PHIRAS && item->amount >= 2)
            condition++;
        if (item->resource_type == SIBUR && item->amount >= 1)
            condition++;
    }
    if (condition == 3)
        return true;
    return false;
}

void cmd_elevation(zappy_t * zappy, client_t* client, char** command)
{
    (void) zappy;
    (void) command;

    wait_time(zappy, 300);
    int i = 0;
    while (elevation_list[i].level) {
        if (elevation_list[i].level == client->player->elevation && \
            elevation_list[i].fct(client->player) == true)
            client->player->elevation += 1;
        i++;
    }
}

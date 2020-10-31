/*
** EPITECH PROJECT, 2020
** zappy
** File description:
** elevation_level.c
*/

#include "zappy_server.h"

bool check_elevation_four(player_t *player)
{
    int condition = 0;

    for (resource_t *item = player->resources; item; item = item->next) {
        if (item->resource_type == LINEMATE && item->amount >= 1)
            condition++;
        if (item->resource_type == PHIRAS && item->amount >= 1)
            condition++;
        if (item->resource_type == SIBUR && item->amount >= 2)
            condition++;
        if (item->resource_type == DERAUMERE && item->amount >= 1)
            condition++;
    }
    if (condition == 4)
        return true;
    return false;
}

bool check_elevation_five(player_t *player)
{
    int condition = 0;

    for (resource_t *item = player->resources; item; item = item->next) {
        if (item->resource_type == LINEMATE && item->amount >= 1)
            condition++;
        if (item->resource_type == MENDIANE && item->amount >= 3)
            condition++;
        if (item->resource_type == SIBUR && item->amount >= 1)
            condition++;
        if (item->resource_type == DERAUMERE && item->amount >= 2)
            condition++;
    }
    if (condition == 4)
        return true;
    return false;
}

bool check_elevation_six(player_t *player)
{
    int condition = 0;

    for (resource_t *item = player->resources; item; item = item->next) {
        if (item->resource_type == LINEMATE && item->amount >= 1)
            condition++;
        if (item->resource_type == PHIRAS && item->amount >= 1)
            condition++;
        if (item->resource_type == SIBUR && item->amount >= 3)
            condition++;
        if (item->resource_type == DERAUMERE && item->amount >= 2)
            condition++;
    }
    if (condition == 4)
        return true;
    return false;
}

bool check_elevation_seven(player_t *player)
{
    int condition = 0;

    for (resource_t *item = player->resources; item; item = item->next) {
        if (item->resource_type == LINEMATE && item->amount >= 2)
            condition++;
        if (item->resource_type == PHIRAS && item->amount >= 2)
            condition++;
        if (item->resource_type == SIBUR && item->amount >= 2)
            condition++;
        if (item->resource_type == DERAUMERE && item->amount >= 2)
            condition++;
        if (item->resource_type == MENDIANE && item->amount >= 1)
            condition++;
        if (item->resource_type == THYSTAME && item->amount >= 1)
            condition++;
    }
    if (condition == 5)
        return true;
    return false;
}

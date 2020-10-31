/*
** EPITECH PROJECT, 2020
** player.h
** File description:
** player
*/

#ifndef ZAPPY_PLAYER_H_
#define ZAPPY_PLAYER_H_

#include <errno.h>
#include <stdbool.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "map.h"
#include "network.h"

typedef struct player_s {
    int elevation;
    char *uuid;
    char *name;
    resource_t *resources;
    bool alive;
    int view_direction;
    char* team_name;
    map_tile_t *current_tile;
    struct player_s *next;
} player_t;

typedef struct elevation_s {
    int level;
    bool (*fct)(player_t *player);
} elevation_t;

typedef struct egg_s {
    client_t *client;
    bool connected;
} egg_t;

player_t *create_player(client_t* client);
player_t* new_player(player_t **player, client_t* client);
void destroy_players(player_t *player);
player_t* find_player_by_uuid(player_t *list, const char* uuid);

bool check_elevation_one(player_t *player);
bool check_elevation_two(player_t *player);
bool check_elevation_three(player_t *player);
bool check_elevation_four(player_t *player);
bool check_elevation_five(player_t *player);
bool check_elevation_six(player_t *player);
bool check_elevation_seven(player_t *player);

resource_t *add_resource(resource_t *current, enum RESOURCE_TYPE type);
resource_t *create_inventory(player_t *player);
resource_t *get_resource(player_t *player, enum RESOURCE_TYPE type);
int player_size(player_t *list);
#endif /* ! ZAPPY_PLAYER_H_ */

/*
** EPITECH PROJECT, 2020
** zappy
** File description:
** Server
*/

#ifndef MY_ZAPPY_SERVER_H_
#define MY_ZAPPY_SERVER_H_

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>

#include "network.h"
#include "player.h"
#include "map.h"

#define USAGE "USAGE: ./zappy_server -p port -x width -y height -n name1 \
name2 ... -c clientsNb\n\
-f freq\n      port       is the port number\n      \
width      is the width of the world\n      \
height     is the height of the world\n      \
nameX      is the name of the team X\n      \
clientsNb  is the number of authorized clients per team\n      \
freq       is the reciprocal of time unit for execution of actions\n"

typedef struct team_s {
    char *name;
    int max;
    struct team_s *next;
} team_t;

typedef struct data_s {
    int optIndex;
    int port;
    int width;
    int height;
    int nbclient;
    int freq;
} data_t;

typedef struct zappy_s {
    network_t* network;
    data_t *data;
    team_t *teams;
    bool loop;
    player_t* players;
    map_t* maps;
} zappy_t;

typedef struct fct_tab_s {
    char* str;
    void (*fct)(zappy_t * zappy, client_t* client, char** command);
} fct_tab_t;

typedef struct option_s {
    char *option;
    int (*fct)(zappy_t *, char **, int);
} option_t;

// Core
zappy_t* zappy_create(char** av);
void zappy_destroy(zappy_t* zappy);
void zappy_disptach(zappy_t* zappy, client_t* client, const char* cmd);
void wait_time(zappy_t* zappy, int action);

// Network
int network_loop(zappy_t* zappy);
void clients_handle(zappy_t* zappy, int sd, fd_set readfds);

// Utils & Divers
void send_to(int fd, const char* str);
char** parse_str(const char* str);
char* format_str(char* str);
char* generate_uuid(void);
map_tile_t *random_spawn_position(zappy_t *zappy);
bool spawn_egg(zappy_t *zappy, client_t *client);

// Commands
void cmd_ping(zappy_t * zappy, client_t* client, char** command);
void cmd_time(zappy_t * zappy, client_t* client, char** command);
void cmd_broadcast(zappy_t * zappy, client_t* client, char** command);
int cmd_team_register(zappy_t* zappy, client_t* client, char** parse_cmd);
void cmd_look(zappy_t * zappy, client_t* client, char** command);
void cmd_fork(zappy_t *zappy, client_t *client, char **command);
void cmd_forward(zappy_t * zappy, client_t* client, char** command);
void cmd_right(zappy_t * zappy, client_t* client, char** command);
void cmd_left(zappy_t * zappy, client_t* client, char** command);
void cmd_inventory(zappy_t * zappy, client_t* client, char** command);
void cmd_elevation(zappy_t * zappy, client_t* client, char** command);
void cmd_gui_players(zappy_t * zappy, client_t* client, char** command);
void cmd_take_object(zappy_t *zappy, client_t *client, char **command);

int loop_option(zappy_t *net, char **args);
int check_option(zappy_t *net, char **args, int i);
int init_port(zappy_t *net, char **args, int i);
int init_width(zappy_t *net, char **args, int i);
int init_height(zappy_t *net, char **args, int i);
int init_teams(zappy_t *net, char **args, int i);
int init_client(zappy_t *net, char **args, int i);
int init_freq(zappy_t *net, char **args, int i);
int create_team(team_t **team, char **args, int j);

team_t* team_found_by_name(team_t* teams, char* str);

#endif /* !MY_ZAPPY_SERVER_H_ */

/*
** EPITECH PROJECT, 2020
** zappy
** File description:
** AI
*/


#ifndef MY_ZAPPY_AI_H_
#define MY_ZAPPY_AI_H_

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "network.h"

// State: 0 not init / 1 wait server response / 2 ready to play
typedef struct zappy_s {
    int port;
    char *team;
    char *machine;
    network_t* network;
    bool loop;
    int state;
    int width;
    int height;
} zappy_t;

typedef struct fct_tab_s {
    char* str;
    void (*fct)(zappy_t * zappy, char** command);
} fct_tab_t;

zappy_t* zappy_create(int ac, char **av);
void zappy_destroy(zappy_t* zappy);
void zappy_loop(zappy_t* zappy);
void zappy_disptach_recv(zappy_t* zappy, const char* cmd);
const char *retrieve_look(const char *str);

void network_bind(zappy_t* teams, int socket, fd_t* fds);
void network_recv(zappy_t* zappy);
void network_loop(zappy_t* zappy);
void server_send(zappy_t* zappy, const char* str);

char* format_str(char* str);
char** parse_str(const char* str);
int arraylen(char** array);
bool str_is_int(char* str);
int check_option(int ac, char **av, zappy_t *zappy);
bool check_alphanum(const char *str);

void cmd_register(zappy_t* zappy, char** command);
void cmd_death(zappy_t* zappy, char** command);

int cmds_handle(int fd);

#endif /* !MY_ZAPPY_AI_H_ */

/*
** EPITECH PROJECT, 2020
** client
** File description:
** my_teams
*/

#ifndef MY_TEAMS_H_
#define MY_TEAMS_H_

#include <stdbool.h>
#include <stdio.h>
#include <ctype.h>

#include "network.h"
#include "../../libs/myteams/logging_client.h"

typedef struct buffer_s {
    char* local;
    char* send;
} buffer_t;

typedef struct user_s {
    char *uuid;
    char *username;
    bool status;
}user_t;

typedef struct my_teams_t {
    user_t *user;
    server_t* server;
    buffer_t* buffer;
    bool loop;
} my_teams_t;

typedef struct fct_tab_s {
    char* str;
    void (*fct)(my_teams_t * teams, char** command);
} fct_tab_t;

bool has_error(const int ac, const char** av);
int print_help(void);

void core_loop(my_teams_t* teams);
void core_prompt(my_teams_t* teams);

void network_bind(my_teams_t* teams, int socket, fd_t* fds);
void network_recv(my_teams_t* teams);

void server_dispatch(my_teams_t* teams, const char* str);
void server_send(my_teams_t* teams, const char* str);

void local_dispatch(my_teams_t* teams, const char* cmd);

void command_quit(my_teams_t* teams, char** command);
void command_ping(my_teams_t* teams, char** command);

void send_command(my_teams_t *teams, char const *uuid, char *word);
void command_pong(my_teams_t* teams, char** command);
void command_login(my_teams_t* teams, char** command);
void command_login_ok(my_teams_t* teams, char** command);
void command_already_logged(my_teams_t* teams, char** command);
void command_not_logged(my_teams_t* teams, char** command);
void command_logout(my_teams_t* teams, char** command);
void command_users(my_teams_t* teams, char** command);
void command_user_info(my_teams_t* teams, char** command);
void command_user_not_found(my_teams_t* teams, char** command);
void command_info(my_teams_t* teams, char** command);
void command_name_too_long(my_teams_t* teams, char** command);
void command_users_list(my_teams_t* teams, char** command);
char **parse_str(char *str, char c);
void command_logout_ok(my_teams_t* teams, char** command);
void command_message(my_teams_t* teams, char** command);
void command_send(my_teams_t* teams, char** command);
void command_body_too_long(my_teams_t* teams, char** command);
void command_sent_message(my_teams_t* teams, char** command);
void command_new_message(my_teams_t* teams, char** command);
void command_error(my_teams_t* teams, char** command);
void invalid_charactere(my_teams_t* teams, char** command);
void command_help(my_teams_t* teams, char** command);

#endif /* !MY_TEAMS_H_ */

/*
** EPITECH PROJECT, 2020
** server
** File description:
** my_teams
*/

#ifndef MY_TEAMS_H_
#define MY_TEAMS_H_

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#include "../../libs/myteams/logging_server.h"
#include "errors.h"
#include "network.h"
#include "sessions.h"
#include "private_messages.h"
#include "teams.h"

#define MAX_NAME_LENGTH 32
#define MAX_DESCRIPTION_LENGTH 255
#define MAX_BODY_LENGTH 512

bool has_error(const int ac, const char** av);
int print_help(void);

typedef struct my_teams_s {
    network_t clients;
    server_t server;
    struct sockaddr_in address;
    sessions_t sessions;
    conversation_t* conversations;
    teams_t* teams;
} my_teams_t;

typedef struct fct_tab_s {
    char* str;
    void (*fct)(my_teams_t * teams, client_t* client, char** command);
} fct_tab_t;

void newtork_init(my_teams_t* teams, int port);
int create_server_socket(server_t *server);
bool new_client(my_teams_t* teams, int addrlen, fd_set readfds);
void handle_client(my_teams_t* teams, int addrlen, int sd, fd_set readfds);

int connections(my_teams_t* teams);
void dispatch_cmd(my_teams_t* teams, client_t* client, const char* cmd);
void send_to(int fd, char* str);

/*
 * Utils
 */
char **parse_str(char *str, char c);
char* rfc_str(int code, char* str);
char* generate_uuid(void);
char* clean_cmd(const char* cmd);

char **command_parsing(const char *str);
int params_count(char** commands);

/*
 * Middleware
 */
bool is_connected(client_t* client);

/*
 * Commands
 */
void command_ping(my_teams_t * teams, client_t* client, char** command);
void command_logout(my_teams_t * teams, client_t* client, char** command);
void command_login(my_teams_t * teams, client_t* client, char** command);
void command_users(my_teams_t * teams, client_t* client, char** command);
void command_user(my_teams_t * teams, client_t* client, char** command);
void command_user_info(my_teams_t * teams, client_t* client, char** command);

void command_messages(my_teams_t * teams, client_t* client, char** command);
void command_messages_send(my_teams_t * teams, client_t* client, \
char** command);

void command_teams_create(my_teams_t * teams, client_t* client, char** command);
void command_teams_list(my_teams_t * teams, client_t* client, char** command);
void command_teams_info(my_teams_t * teams, client_t* client, char** command);
void command_teams_subscribe(my_teams_t * teams, client_t* client, \
char** command);
void command_teams_unsubscribe(my_teams_t * teams, client_t* client, \
char** command);
void command_teams_subscribe_list(my_teams_t * teams, client_t* client, \
char** command);

void command_disptach_create(my_teams_t * teams, client_t* client, \
char** command);
void command_disptach_info(my_teams_t * teams, client_t* client, \
char** command);
void command_disptach_list(my_teams_t * teams, client_t* client, \
char** command);


#endif /* !MY_TEAMS_H_ */

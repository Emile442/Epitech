/*
** EPITECH PROJECT, 2020
** PSU_minishell1_2018
** File description:
** MY_SHELL
*/

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>

#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>

#include <errno.h>

#ifndef MY_FTP_H
#define MY_FTP_H

#define MAX_CLIENT 10

typedef struct server_s {
    bool exit;
    struct sockaddr_in socket_params;
    int fd;
    const char* path;
} server_t;

typedef enum ftp_mode_e {
    DEFAULT = 0,
    PASV = 1,
    ACTIVE = 2
} ftp_mode_t;

typedef struct data_s {
    bool exit;
    int port;
    char* ip;
    struct sockaddr_in socket_params;
    int fd;
} data_t;

typedef struct client_s {
    bool exit;
    struct sockaddr_in socket_params;
    int fd;
    int pid;
    char* username;
    bool auth;
    char* path;
    ftp_mode_t ftp_mode;
    data_t* data;
} client_t;

typedef struct fct_tab_s
{
    char* str;
    void (*fct)(client_t* client, char** command);
} fct_tab_t;

typedef struct accounts_tab_s
{
    char* username;
    char* password;
    char* home;
} accounts_tab_t;

server_t* server_init(int port, const char* path);
void server_wait_connection(server_t* server);

client_t* client_init(server_t* server);
void new_client(client_t* client);

void exit_with_error(char* msg);
char **parse_str(char *str, char c);
int strlen_array(char** array);
int rdm_number(int min, int max);

void ftp_response(client_t* client, const char* str, const char* code);

bool data_middleware(client_t* client, char** cmd);
bool auth_middleware(client_t* client, char** cmd);

void dispatch_cmd(client_t* client, char* cmd);

void command_quit(client_t* client, char** cmd);
void cmd_auth_username(client_t* client, char** cmd);
void cmd_auth_password(client_t* client, char** cmd);
void cmd_pwd(client_t* client, char** cmd);
void cmd_cwd(client_t* client, char** cmd);
void cmd_cdup(client_t* client, char** cmd);
void cmd_noop(client_t* client, char** cmd);
void cmd_help(client_t* client, char** cmd);
void cmd_port(client_t* client, char** cmd);
void cmd_pasv(client_t* client, char** cmd);
void cmd_list(client_t* client, char** cmd);

data_t* data_init(char* ip, int port, mode_t mode);

#endif

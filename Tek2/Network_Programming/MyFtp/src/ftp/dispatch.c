/*
** EPITECH PROJECT, 2020
** MyFtp
** File description:
** Dispatch
*/

#include "ftp.h"

const fct_tab_t fct_tab[] = {
    {"QUIT", command_quit},
    {"USER", cmd_auth_username},
    {"PASS", cmd_auth_password},
    {"PWD", cmd_pwd},
    {"CWD", cmd_cwd},
    {"CDUP", cmd_cdup},
    {"NOOP", cmd_noop},
    {"HELP", cmd_help},
    {"PORT", cmd_port},
    {"PASV", cmd_pasv},
    {NULL, NULL}
};

bool prevent_null(client_t* client, char** cmd)
{
    if (cmd == NULL || cmd[0] == NULL) {
        if (client->auth)
            ftp_response(client, "Command not found", "500");
        else
            ftp_response(client, "Please login with USER and PASS.", "530");
        return (true);
    }
    return (false);
}

void free_cmd(char* cmd, char** parse_cmd)
{
    if (parse_cmd)
        free(parse_cmd);
    if (cmd)
        free(cmd);
}

void dispatch_cmd(client_t* client, char* cmd)
{
    char** parse_cmd = parse_str(cmd, ' ');
    bool cmd_found = false;

    printf("\033[0;32m[FTP SERVER][CLIENT %d][CMD]: %s\033[0m\n", client->fd, \
    parse_cmd[0]);
    if (prevent_null(client, parse_cmd))
        return free_cmd(cmd, parse_cmd);
    if (!auth_middleware(client, parse_cmd) || !data_middleware(client, \
        parse_cmd))
        return free_cmd(cmd, parse_cmd);
    for (int i = 0; fct_tab[i].str && !cmd_found; i++) {
        if (strcmp(fct_tab[i].str, parse_cmd[0]) == 0) {
            cmd_found = true;
            fct_tab[i].fct(client, parse_cmd);
        }
    }
    if (!cmd_found)
        ftp_response(client, "Command not found", "500");
    free_cmd(cmd, parse_cmd);
}

/*
** EPITECH PROJECT, 2020
** myteams_cli
** File description:
** dispatch.c
*/

#include "my_teams.h"

const fct_tab_t fct_tab[] = {
    {"/quit", command_quit},
    {"/ping", command_ping},
    {"/help", command_help},
    {"/login", command_login},
    {"/logout", command_logout},
    {"/users", command_users},
    {"/user", command_info},
    {"/messages", command_message},
    {"/send", command_send},
    {NULL, NULL}
};

static void free_cmd(char* cmd, char** parse_cmd)
{
    for (int i = 0; parse_cmd[i]; i++)
        free(parse_cmd[i]);
    free(parse_cmd);
    if (cmd)
        free(cmd);
}

void local_dispatch(my_teams_t* teams, const char* cmd)
{
    char* copy = strdup(cmd);
    char** parse_cmd = parse_str(copy, ' ');
    bool cmd_found = false;

    for (int i = 0; fct_tab[i].str && !cmd_found; i++) {
        if (strcmp(fct_tab[i].str, parse_cmd[0]) == 0) {
            cmd_found = true;
            fct_tab[i].fct(teams, parse_cmd);
        }
    }
    if (!cmd_found)
        printf("Command not found, use /help for show available commands\n");
    free_cmd(copy, parse_cmd);
}
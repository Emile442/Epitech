/*
** EPITECH PROJECT, 2020
** myteams_cli
** File description:
** dispatch.c
*/

#include "my_teams.h"

const fct_tab_t server_cmd[] = {
    {"145", command_pong},
    {"101", command_login_ok},
    {"102", command_already_logged},
    {"103", command_not_logged},
    {"104", command_logout_ok},
    {"105", command_users_list},
    {"106", command_user_info},
    {"107", command_user_not_found},
    {"108", command_info},
    {"109", command_name_too_long},
    {"120", command_new_message},
    {"121", command_sent_message},
    {"122", command_body_too_long},
    {"404", command_error},
    {"505", invalid_charactere},
    {NULL, NULL}
};

static void free_cmd(char* cmd, char** parse_cmd)
{
    if (parse_cmd)
        free(parse_cmd);
    if (cmd)
        free(cmd);
}

void server_dispatch(my_teams_t* teams, const char* str)
{
    char* copy = strdup(str);
    char** parse_cmd = parse_str(copy, ' ');
    bool cmd_found = false;

    for (int i = 0; server_cmd[i].str && !cmd_found; i++) {
        if (strcmp(server_cmd[i].str, parse_cmd[0]) == 0) {
            cmd_found = true;
            server_cmd[i].fct(teams, parse_cmd);
        }
    }
    if (!cmd_found) {
        printf("%s\n", parse_cmd[1]);
    }
    free_cmd(copy, parse_cmd);
}
/*
** EPITECH PROJECT, 2020
** server
** File description:
** dispatch
*/

#include "my_teams.h"

const fct_tab_t fct_tab[] = {
    {"ping", command_ping},
    {"login", command_login},
    {"logout", command_logout},
    {"users", command_users},
    {"user", command_user},
    {"send", command_messages_send},
    {"messages", command_messages},
    {"subscribed", command_teams_subscribe_list},
    {"subscribe", command_teams_subscribe},
    {"unsubscribe", command_teams_unsubscribe},
    {"info", command_disptach_info},
    {"create", command_disptach_create},
    {"list", command_disptach_list},
    {NULL, NULL}
};

void free_cmd(char* cmd, char** parse_cmd)
{
    if (parse_cmd)
        free(parse_cmd);
    if (cmd)
        free(cmd);
}

void dispatch_cmd(my_teams_t* teams, client_t* client, const char* cmd)
{
    char* copy = strdup(cmd);
    char** parse_cmd = command_parsing(copy);
    bool cmd_found = false;

    printf("DEBUG\n");
    for (int j = 0; parse_cmd[j]; j++) {
        printf("%d: [%s]\n", j, parse_cmd[j]);
    }
    for (int i = 0; fct_tab[i].str && !cmd_found; i++) {
        if (strcmp(fct_tab[i].str, parse_cmd[0]) == 0) {
            cmd_found = true;
            fct_tab[i].fct(teams, client, parse_cmd);
        }
    }
    if (!cmd_found)
        send_to(client->socket, rfc_str(404, NOT_FOUND));
}

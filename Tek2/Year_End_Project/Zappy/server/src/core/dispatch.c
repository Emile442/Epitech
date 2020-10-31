/*
** EPITECH PROJECT, 2020
** zappy
** File description:
** disptach
*/

#include "zappy_server.h"

const fct_tab_t cmd_lists[] = {
    {"ping", cmd_ping},
    {"time", cmd_time},
    {"Broadcast", cmd_broadcast},
    {"Look", cmd_look},
    {"Forward", cmd_forward},
    {"Right", cmd_right},
    {"Left", cmd_left},
    {"Inventory", cmd_inventory},
    {"Incantation", cmd_elevation},
    {"Fork", cmd_fork},
    {"gui_players", cmd_gui_players},
    {"Take", cmd_take_object},
    {NULL, NULL}
};

void free_cmd(char** parse_cmd)
{
    for (int i = 0; parse_cmd[i] != NULL; i++)
        free(parse_cmd[i]);
    if (parse_cmd != NULL)
        free(parse_cmd);
}

void zappy_disptach(zappy_t* zappy, client_t* client, const char* cmd)
{
    char** parse_cmd = parse_str(cmd);
    bool cmd_found = false;

    if (parse_cmd[0][0] == '\0')
        return;
    for (int i = 0; cmd_lists[i].str && !cmd_found; i++) {
        if (strcmp(cmd_lists[i].str, parse_cmd[0]) == 0 && \
        client->player != NULL) {
            cmd_found = true;
            cmd_lists[i].fct(zappy, client, parse_cmd);
        }
    }
    if (!cmd_found)
        cmd_found = cmd_team_register(zappy, client, parse_cmd);
    if (!cmd_found)
        send_to(client->socket, format_str("ko"));
    free_cmd(parse_cmd);
}

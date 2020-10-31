/*
** EPITECH PROJECT, 2020
** myteams_server
** File description:
** cmd_list.c
*/

#include "my_teams.h"

static bool cmd_has_error(client_t* client, char** command)
{
    (void) command;
    if (!is_connected(client)) {
        send_to(client->socket, rfc_str(103, NOT_LOGGED));
        return (true);
    }
    return (false);
}

static void print_all_teams(teams_t** list, int socket)
{
    int len = 1;
    char* rt;

    for (teams_t *tmp = *list; tmp; tmp = tmp->next)
        len += strlen(teams_str(tmp)) + 1;
    rt = calloc(len, sizeof(char));
    for (teams_t *tmp = *list; tmp; tmp = tmp->next) {
        strcat(rt, teams_str(tmp));
        if (tmp->next != NULL)
            strcat(rt, "#");
    }
    send_to(socket, rfc_str(153, rt));
    free(rt);
}

void command_teams_list(my_teams_t * teams, client_t* client, char** command)
{
    if (cmd_has_error(client, command))
        return;
    print_all_teams(&teams->teams, client->socket);
}
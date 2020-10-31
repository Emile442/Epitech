/*
** EPITECH PROJECT, 2020
** myteams_server
** File description:
** cmd_list.c
*/


#include "my_teams.h"

static bool cmd_has_error(client_t* client, char** command)
{
    (void)command;
    if (!is_connected(client)) {
        send_to(client->socket, rfc_str(103, NOT_LOGGED));
        return (true);
    }
    return (false);
}

char* teams_sub_str(teams_t* team)
{
    int len = strlen(teams_str(team)) + 1;
    char* rt;

    for (user_t *tmp = team->subscribers; tmp; tmp = tmp->next)
        len += strlen(get_user_str(tmp, 0)) + 1;
    rt = calloc(len, sizeof(char));
    strcat(rt, teams_str(team));
    strcat(rt, "/");
    for (user_t *tmp = team->subscribers; tmp; tmp = tmp->next) {
        strcat(rt, get_user_str(tmp, 0));
        if (tmp->next != NULL)
            strcat(rt, "#");
    }
    return (rt);
}

bool get_team_sub(my_teams_t * teams, client_t* client, \
char** command)
{
    teams_t* team;
    char* rt;

    if (command[1] != NULL) {
        team = teams_get_by_uuid(teams->teams, command[1]);
        if (team == NULL) {
            send_to(client->socket, rfc_str(154, TEAMS_NOT_FOUND));
            return (true);
        }
        rt = teams_sub_str(team);
        send_to(client->socket, rfc_str(159, rt));
        free(rt);
        return (true);
    }
    return (false);
}

void command_teams_subscribe_list(my_teams_t * teams, client_t* client, \
char** command)
{
    int len = 1;
    char* rt;

    if (cmd_has_error(client, command))
        return;
    if (get_team_sub(teams, client, command))
        return;
    for (teams_t *tmp = teams->teams; tmp; tmp = tmp->next)
        len += strlen(teams_sub_str(tmp)) + 1;
    rt = calloc(len, sizeof(char));
    for (teams_t *tmp = teams->teams; tmp; tmp = tmp->next) {
        strcat(rt, teams_sub_str(tmp));
        if (tmp->next != NULL)
            strcat(rt, ";");
    }
    send_to(client->socket, rfc_str(159, rt));
    free(rt);
}

/*
** EPITECH PROJECT, 2020
** myteams_server
** File description:
** teams_list.c
*/

#include "my_teams.h"

void teams_push(teams_t ** list, teams_t* team)
{
    team->next = (*list);
    (*list) = team;
}

teams_t* teams_create(const char* name, const char* desc)
{
    teams_t* team = malloc(sizeof(teams_t));

    team->uuid = generate_uuid();
    team->name = strdup(name);
    team->description = strdup(desc);
    team->subscribers = NULL;
    return (team);
}

teams_t* teams_get_by_uuid(teams_t *list, const char* uuid)
{
    teams_t* tmp = list;

    if (list == NULL)
        return (NULL);
    for (int i = 0; tmp; tmp = tmp->next, i++) {
        if (strcmp(tmp->uuid, uuid) == 0)
            return (tmp);
    }
    return (NULL);
}

char* teams_str(const teams_t* team)
{
    int len = strlen(team->uuid) + strlen(team->name) + \
    strlen(team->description) + 3;
    char* rt = calloc(len, sizeof(char));

    sprintf(rt, "%s:%s:%s", team->uuid, team->name, team->description);
    return (rt);
}

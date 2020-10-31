/*
** EPITECH PROJECT, 2020
** myteams_server
** File description:
** teams.h
*/

#ifndef MYTEAMS_SERVER_TEAMS_H
#define MYTEAMS_SERVER_TEAMS_H

typedef struct teams_s {
    char* uuid;
    char* name;
    char* description;
    struct user_s* subscribers;
    struct teams_s* next;
} teams_t;

void teams_push(teams_t ** list, teams_t* team);
teams_t* teams_create(const char* name, const char* desc);
char* teams_str(const teams_t* team);
teams_t* teams_get_by_uuid(teams_t *list, const char* uuid);

#endif //MYTEAMS_SERVER_TEAMS_H

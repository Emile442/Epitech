/*
** EPITECH PROJECT, 2022
** NWP_myftp_2019
** File description:
** Created by Zebens,
*/

#include "my_teams.h"

void initiate_user(my_teams_t* teams, char** command)
{
    char *user = strtok(command[1], ":");
    teams->user->username = user;
    char *uuid = strtok(NULL, ":");
    teams->user->uuid = uuid;
    char *status = strtok(NULL, ":");
    teams->user->status = status;
}

void command_login_ok(my_teams_t* teams, char** command)
{
    initiate_user(teams, command);
    client_event_loggedin(teams->user->uuid, teams->user->username);
}

void command_logout_ok(my_teams_t* teams, char** command)
{
    (void)(command);
    client_event_loggedout(teams->user->uuid, teams->user->username);
}

void command_users_list(my_teams_t* teams, char** command)
{
    (void)(command);
    char *uuid = teams->user->uuid;
    char *username = teams->user->username;
    bool status = teams->user->status;
    client_print_users(uuid, username, status);
}

void command_user_info(my_teams_t* teams, char** command)
{
    (void)(command);
    char *uuid = teams->user->uuid;
    char *username = teams->user->username;
    bool status = teams->user->status;
    client_print_user(uuid, username, status);
}


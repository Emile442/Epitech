/*
** EPITECH PROJECT, 2022
** my_teams
** File description:
** Created by Zebens,
*/

#include "my_teams.h"

void command_user_not_found(my_teams_t* teams, char** command)
{
    (void)(command);
    client_error_unknown_user(teams->user->uuid);
}

void command_already_logged(my_teams_t* teams, char** command)
{
    (void)(command);
    (void)(teams);
    client_error_already_exist();
}

void command_name_too_long(my_teams_t* teams, char** command)
{
    (void)(command);
    (void)(teams);
    client_error_unauthorized();
}

void command_error(my_teams_t* teams, char** command)
{
    (void)(command);
    (void)(teams);
    printf("404 command unknown\n");
}

void invalid_charactere(my_teams_t* teams, char** command)
{
    (void)(command);
    (void)(teams);
    printf("505 bad format\n");
}
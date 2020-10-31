/*
** EPITECH PROJECT, 2020
** myteams_cli
** File description:
** cmd_pong.c
*/

#include "my_teams.h"

void command_pong(my_teams_t* teams, char** command)
{
    (void) teams;
    printf("%s\n", command[1]);
}
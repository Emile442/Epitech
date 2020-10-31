/*
** EPITECH PROJECT, 2020
** myteams_cli
** File description:
** command_quit.c
*/

#include "my_teams.h"

void command_quit(my_teams_t* teams, char** command)
{
    (void) command;
    printf("Goodbye :)\n");
    teams->loop = false;
}
/*
** EPITECH PROJECT, 2020
** myteams_cli
** File description:
** ping.c
*/

#include "my_teams.h"

void command_ping(my_teams_t* teams, char** command)
{
    (void) command;
    server_send(teams, "ping");
}
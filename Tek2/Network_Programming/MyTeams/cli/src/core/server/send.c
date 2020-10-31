/*
** EPITECH PROJECT, 2020
** myteams_cli
** File description:
** send.c
*/

#include "my_teams.h"

void server_send(my_teams_t* teams, const char* str)
{
    memset(teams->buffer->send, '\0', 255);
    strcpy(teams->buffer->send, str);
}
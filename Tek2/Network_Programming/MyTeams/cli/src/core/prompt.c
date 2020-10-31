/*
** EPITECH PROJECT, 2020
** myteams_cli
** File description:
** prompt.c
*/

#include "my_teams.h"

void core_prompt(my_teams_t* teams)
{
    if (read(0, teams->buffer->local, 255)) {
        local_dispatch(teams, teams->buffer->local);
        memset(teams->buffer->local, 0, 255);
    }
}
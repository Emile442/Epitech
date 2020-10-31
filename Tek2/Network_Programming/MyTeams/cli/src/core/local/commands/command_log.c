/*
** EPITECH PROJECT, 2022
** NWP_myftp_2019
** File description:
** Created by Zebens,
*/

#include "my_teams.h"

void send_command(my_teams_t *teams, char const *uuid, char *word)
{
    char *cat;
    if ((cat = malloc(sizeof(*cat) * 255)) == NULL)
        return;

    strcpy(cat, word);
    strcat(cat, uuid);
    server_send(teams, cat);
}

void command_login(my_teams_t* teams, char** command)
{
    char *word = "login \0";

    if (!command[1]) {
        printf("You need a username to connect\n");
        return;
    }
    send_command(teams, command[1], word);
}

void command_users(my_teams_t* teams, char** command)
{
    (void)(command);
    server_send(teams, "users");
}

void command_not_logged(my_teams_t* teams, char** command)
{
    (void)(teams);
    (void)(command);
}

void command_logout(my_teams_t* teams, char** command)
{
    (void)(command);
    server_send(teams, "logout");
}


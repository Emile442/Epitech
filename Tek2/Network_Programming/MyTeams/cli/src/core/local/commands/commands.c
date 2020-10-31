/*
** EPITECH PROJECT, 2022
** my_teams
** File description:
** Created by Zebens,
*/

#include "my_teams.h"

void command_help(my_teams_t* teams, char** command)
{
    (void)(command);
    (void)(teams);
    printf("list of command:\n\t/quit\n\t/login [user]\n");
    printf("\t/logout\n\t/users\n\t/user [uuid]\n");
    printf("\t/messages\n\t/send\n");
}

void command_info(my_teams_t* teams, char** command)
{
    char *word = "user \0";

    if (!command[1]) {
        printf("You need an uuid to check info\n");
        return;
    }
    send_command(teams, command[1], word);
}

void command_message(my_teams_t* teams, char** command)
{
    (void)(command);
    (void)(teams);
}

void command_send(my_teams_t* teams, char** command)
{
    (void)(command);
    (void)(teams);
}
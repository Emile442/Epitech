/*
** EPITECH PROJECT, 2020
** server
** File description:
** cmd_ping
*/

#include "my_teams.h"

void command_ping(my_teams_t * teams, client_t* client, char** command)
{
    (void)teams;
    (void)command;
    char* rt = "pong";

    send_to(client->socket, rfc_str(200, rt));
    printf("%s\n", rt);
}

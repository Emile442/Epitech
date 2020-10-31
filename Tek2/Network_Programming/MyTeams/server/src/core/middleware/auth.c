/*
** EPITECH PROJECT, 2020
** myteams_server
** File description:
** auth.c
*/

#include "my_teams.h"


//send_to(client->socket, rfc_str(103, "Not Logged"));
//send_to(client->socket, rfc_str(102, "Already Logged"));
bool is_connected(client_t* client)
{
    return (client->uuid != NULL);
}
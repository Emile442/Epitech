/*
** EPITECH PROJECT, 2020
** cli
** File description:
** usage
*/

#include "my_teams.h"

int print_help(void)
{
    printf("USAGE:\t./myteams_cli ip port\n\n");
    printf(\
    "\tip\tis the server ip address on which the server socket listens\n");
    printf("\tport\tis the port number on which the server socket listens\n");
    return (0);
}
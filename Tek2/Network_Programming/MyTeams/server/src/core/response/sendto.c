/*
** EPITECH PROJECT, 2020
** server
** File description:
** sendto
*/

#include "my_teams.h"

void send_to(int fd, char* str)
{
    send(fd, str, strlen(str), 0);
}
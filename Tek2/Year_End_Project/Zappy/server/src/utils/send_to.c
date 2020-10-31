/*
** EPITECH PROJECT, 2020
** zappy
** File description:
** Utils Send to FD
*/

#include "zappy_server.h"

void send_to(int fd, const char* str)
{
    send(fd, str, strlen(str), 0);
}

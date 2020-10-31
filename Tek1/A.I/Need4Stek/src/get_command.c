/*
** EPITECH PROJECT, 2019
** matchstick
** File description:
** gnl
*/

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>

char *get_command_player(void)
{
    char *buf = NULL;
    size_t len = 0;
    ssize_t ret = 0;

    ret = getline(&buf, &len, stdin);
    if (ret == -1)
        return (NULL);
    buf[ret - 1] = '\0';
    return (buf);
}

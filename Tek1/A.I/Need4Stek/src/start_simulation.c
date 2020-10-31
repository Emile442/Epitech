/*
** EPITECH PROJECT, 2019
** n4s
** File description:
** start_simulation
*/

#include "n4s.h"

bool start_or_stop_simulation(char *str)
{
    char *buf = NULL;
    int i = 0;

    write(1, str, my_strlen(str));
    buf = get_command_player();
    for (; buf[i] != ':' && buf[i] != '\0'; i++);
    if (buf[i + 1] == 'K' && buf[i + 2] == 'O')
        return (false);
    return (true);
}

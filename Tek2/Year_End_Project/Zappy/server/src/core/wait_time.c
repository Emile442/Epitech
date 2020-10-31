/*
** EPITECH PROJECT, 2020
** zappy
** File description:
** Core CheckTime
*/

#include "zappy_server.h"
#include <unistd.h>

void wait_time(zappy_t* zappy, int action)
{
    sleep(action / zappy->data->freq);
}

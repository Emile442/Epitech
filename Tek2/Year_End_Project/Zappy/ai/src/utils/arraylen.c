/*
** EPITECH PROJECT, 2020
** zappy
** File description:
** zarraylen
*/

#include "zappy_ai.h"

int arraylen(char** array)
{
    int len = 0;
    for (; array[len]; len++);
    return (len);
}

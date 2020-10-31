/*
** EPITECH PROJECT, 2020
** MyFtp
** File description:
** rdm_number
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int rdm_number(int min, int max)
{
    int low = (min < max) ? min : max + 1;
    int big = (min < max) ? max + 1 : min;

    srand(time(NULL));
    return ((rand() % (big - low)) + low);
}

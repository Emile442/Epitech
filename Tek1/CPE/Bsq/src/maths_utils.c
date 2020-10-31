/*
** EPITECH PROJECT, 2018
** maths_utils
** File description:
** Maths Utisl
*/

#include <stdbool.h>
#include "my.h"
#include "bsq.h"

bool range(int a, int b, int value)
{
    if (value >= a && value <= b)
        return (true);
    return (false);
}

int min(int a, int b, int c)
{
    if (a < b)
        return (a < c) ? a : c;
    return (b < c) ? b : c;
}
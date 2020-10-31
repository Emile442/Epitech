/*
** EPITECH PROJECT, 2020
** cpp_d02a_2019
** File description:
** Ex00
*/

#include "double_list.h"

#include <stdlib.h>
#include <stdio.h>

bool double_list_is_empty(double_list_t list)
{
    if (!list)
        return (true);
    return (false);
}

unsigned int double_list_get_size(double_list_t list)
{
    double_list_t tmp = list;
    unsigned int i = 0;

    if (double_list_is_empty(list))
        return (0);
    for (; tmp->next; tmp = tmp->next, i++);
    return (i + 1);
}

void double_list_dump(double_list_t list)
{
    double_list_t tmp = list;

    for (; tmp; tmp = tmp->next)
        printf("%f\n", tmp->value);
}

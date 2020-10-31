/*
** EPITECH PROJECT, 2020
** cpp_d02a_2019
** File description:
** Ex00
*/

#include <stdlib.h>
#include <stdio.h>

#include "double_list.h"

void double_list_reverse(double_list_t *list);

double double_list_get_elem_at_front(double_list_t list)
{
    if (double_list_is_empty(list))
        return (0);
    return (list->value);
}

double double_list_get_elem_at_back(double_list_t list)
{
    double_list_t tmp = list;

    if (double_list_is_empty(list))
        return (0);
    for (; tmp->next; tmp = tmp->next);
    return (tmp->value);
}

double double_list_get_elem_at_position(double_list_t list,
unsigned int position)
{
    double_list_t tmp = list;

    if (double_list_is_empty(list))
        return (0);
    if (position == 0)
        return (double_list_get_elem_at_front(list));
    if (double_list_get_size(list) < position)
        return (false);
    for (unsigned int i = 0; tmp->next && i != position; tmp = tmp->next, i++);
    return (tmp->value);
}

doublelist_node_t *double_list_get_first_node_with_value(double_list_t list,
double value)
{
    for (int i = 0; list != NULL; list = list->next, i++)
        if (list->value == value)
            return (list);
    return (NULL);
}

/*
** EPITECH PROJECT, 2020
** cpp_d02a_2019
** File description:
** Ex00
*/

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#include "double_list.h"

void double_list_reverse(double_list_t *list);

bool double_list_add_elem_at_front(double_list_t *front_ptr, double elem)
{
    double_list_t new = malloc(sizeof(front_ptr));

    if (new == NULL)
        return (false);
    new->value = elem;
    new->next = *front_ptr;
    *front_ptr = new;
    return (true);
}

bool double_list_add_elem_at_back(double_list_t *front_ptr, double elem)
{
    double_list_reverse(front_ptr);
    if (!double_list_add_elem_at_front(front_ptr, elem))
        return (false);
    double_list_reverse(front_ptr);
    return (true);
}

bool double_list_add_elem_at_position(double_list_t *front_ptr, double elem,
unsigned int position)
{
    double_list_t list = *front_ptr;
    double_list_t new = malloc(sizeof(front_ptr));

    if (!new)
        return (false);
    if (double_list_is_empty(*front_ptr))
        return (false);
    if (double_list_get_size(list) < position)
        return (false);
    if (position == 0)
        return (double_list_add_elem_at_front(front_ptr, elem));
    new->value = elem;
    while (--position)
        list = list->next;
    new->next = list->next;
    list->next = new;
    return (true);
}

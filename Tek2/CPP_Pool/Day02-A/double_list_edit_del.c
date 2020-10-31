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

bool double_list_del_elem_at_front(double_list_t *front_ptr)
{
    if (double_list_is_empty(*front_ptr))
        return (false);
    *front_ptr = (*front_ptr)->next;
    return (true);
}

bool double_list_del_elem_at_back(double_list_t *front_ptr)
{
    double_list_reverse(front_ptr);
    if (!double_list_del_elem_at_front(front_ptr))
        return (false);
    double_list_reverse(front_ptr);
    return (true);
}

bool double_list_del_elem_at_position(double_list_t *front_ptr, \
unsigned int position)
{
    double_list_t list = *front_ptr;
    double_list_t new;

    if (double_list_is_empty(*front_ptr))
        return (false);
    if (double_list_get_size(list) - 1 < position)
        return (false);
    if (position == 0)
        return (double_list_del_elem_at_front(front_ptr));
    while (--position)
        list = list->next;
    new = list->next;
    list->next = new->next;
    return (true);
}

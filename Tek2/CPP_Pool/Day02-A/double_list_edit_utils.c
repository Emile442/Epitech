/*
** EPITECH PROJECT, 2020
** cpp_d02a_2019
** File description:
** Ex00
*/

#include <stdlib.h>

#include "double_list.h"

void double_list_reverse(double_list_t *list)
{
    double_list_t prev = NULL;
    double_list_t current = *list;
    double_list_t next = NULL;

    while (current) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    *list = prev;
}

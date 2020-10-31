/*
** EPITECH PROJECT, 2018
** my_params_to_list
** File description:
** my_params_to_list
*/

#include <stdlib.h>
#include "my.h"
#include "mylist.h"

void my_rev_list(linked_list_t **begin)
{
    linked_list_t *next = malloc(sizeof(*next));
    linked_list_t *current = *begin;
    linked_list_t *prev = malloc(sizeof(*prev));

    for (int i = 0; begin; i++) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    *begin = prev;
}
/*
** EPITECH PROJECT, 2018
** pushswap_func
** File description:
** PushSwap Function
*/

#include <stddef.h>
#include <stdlib.h>

#include "pushswap.h"
#include "my.h"

void ra(list_t **list)
{
    int val;

    if (*list != NULL) {
        val = (*list)->value;
        pull_list(list);
        reverse_list(list);
        push_list(list, val);
        reverse_list(list);
    }
}

void pb(list_t **src, list_t **dest)
{
    int first_a;

    if (*src != NULL) {
        first_a = (*src)->value;
        pull_list(src);
        push_list(dest, first_a);
    }
}

void pa(list_t **src, list_t **dest)
{
    int first_b;

    if (*src != NULL) {
        first_b = (*src)->value;
        pull_list(src);
        push_list(dest, first_b);
    }
}
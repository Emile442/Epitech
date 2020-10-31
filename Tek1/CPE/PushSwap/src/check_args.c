/*
** EPITECH PROJECT, 2018
** check_args
** File description:
** Check Args
*/

#include <stddef.h>
#include <stdlib.h>

#include "my.h"
#include "pushswap.h"

bool check_already_order(list_t *list_a)
{
    list_t *current = list_a;
    int prev;

    if (current == NULL)
        return (true);
    prev = current->value;
    while (current) {
        if (current->value < prev)
            return (false);
        prev = current->value;
        current = current->next;
    }
    return (true);
}
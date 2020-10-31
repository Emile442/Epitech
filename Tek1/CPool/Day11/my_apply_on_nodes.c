/*
** EPITECH PROJECT, 2018
** my_apply_on_nodes
** File description:
** Apply function
*/

#include <stdlib.h>
#include "my.h"
#include "mylist.h"

int my_apply_on_nodes(linked_list_t *begin, int (*f) (void *))
{
    int i = 0;

    for (; begin; i++) {
        (*f)(begin->data);
        begin = begin->next;
    }
    return (0);
}
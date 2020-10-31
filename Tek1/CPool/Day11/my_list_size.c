/*
** EPITECH PROJECT, 2018
** my_list_size
** File description:
** Return (int) fo list size
*/

#include <stdlib.h>
#include "my.h"
#include "mylist.h"

linked_list_t *my_params_to_list(int ac, char * const *av);

int my_list_size(linked_list_t const *begin)
{
    int i = 0;

    for (; begin; i++) {
        begin = begin->next;
    }
    return (i);
}
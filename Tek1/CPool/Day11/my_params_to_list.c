/*
** EPITECH PROJECT, 2018
** my_params_to_list
** File description:
** my_params_to_list
*/

#include <stdlib.h>
#include "my.h"
#include "mylist.h"

void push_data(linked_list_t **tmp, char *arg)
{
    linked_list_t *new = malloc(sizeof(*new));
    new->data = arg;
    new->next = (*tmp)->next;
    (*tmp)->next = new;
}

linked_list_t *my_params_to_list(int ac, char * const *av)
{
    linked_list_t *tmp = malloc(sizeof(*tmp));

    for (int i = 0; i < ac; i++) {
        push_data(&tmp, av[i]);
    }
    return (tmp->next);
}
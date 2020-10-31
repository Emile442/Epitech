/*
** EPITECH PROJECT, 2018
** list_func
** File description:
** List Helper
*/

#include <stddef.h>
#include <stdlib.h>

#include "pushswap.h"
#include "my.h"

int found_the_smaller(list_t *list)
{
    list_t *tmp = list;
    int val = tmp->value;

    for (; tmp; tmp = tmp->next)
        if (tmp->value < val)
            val = tmp->value;
    return (val);
}

int count_list(list_t **list)
{
    list_t *tmp = *list;
    int count = 0;

    for (; tmp; tmp = tmp->next)
        count++;
    return (count);
}

void reverse_list(list_t **list)
{
    list_t *prev = NULL;
    list_t *current = *list;
    list_t *next = NULL;

    while (current) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    *list = prev;
}

void push_list(list_t **list, int value)
{
    list_t* new_val = malloc(sizeof(list_t));

    new_val->value = value;
    new_val->next = (*list);
    (*list) = new_val;
}

void pull_list(list_t **list)
{
    if (*list != NULL)
        (*list) = (*list)->next;
}
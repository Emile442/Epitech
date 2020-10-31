/*
** EPITECH PROJECT, 2018
** map_func
** File description:
** Map Func
*/
#include "my.h"
#include "my_runner.h"

int count_list(map_t **list)
{
    map_t *tmp = *list;
    int count = 0;

    for (; tmp; tmp = tmp->next)
        count++;
    return (count);
}

void reverse_list(map_t **list)
{
    map_t *prev = NULL;
    map_t *current = *list;
    map_t *next = NULL;

    while (current) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    *list = prev;
}

void push_list(map_t **list, int value)
{
    map_t* new_val = malloc(sizeof(map_t));

    new_val->value = value;
    new_val->next = (*list);
    (*list) = new_val;
}

void pull_list(map_t **list)
{
    if (*list != NULL)
        (*list) = (*list)->next;
}

int next_list(map_t **list)
{
    int tmp = -1;

    if (*list != NULL)
        tmp = (*list)->value;
    pull_list(list);
    return (tmp);
}

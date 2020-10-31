/*
** EPITECH PROJECT, 2019
** 42sh
** File description:
** utils/chained_list
*/

#include "sh.h"

void print_list(list_t **list)
{
    list_t *tmp = *list;

    for (; tmp; tmp = tmp->next)
        printf("%s=%s\n", tmp->data->key, tmp->data->value);
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

void push_list(list_t **list, data_t* data)
{
    list_t* new_val = malloc(sizeof(list_t));

    new_val->data = data;
    new_val->next = (*list);
    (*list) = new_val;
}

void pull_list(list_t **list)
{
    if (*list != NULL)
        (*list) = (*list)->next;
}

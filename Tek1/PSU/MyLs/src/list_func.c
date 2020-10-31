/*
** EPITECH PROJECT, 2019
** PSU_my_ls_2018
** File description:
** List Helper
*/

#include "my_ls.h"
#include "my.h"

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

void push_list(list_t **list, file_t* value)
{
    list_t* new_val = malloc(sizeof(list_t));

    if (new_val == NULL)
        exit(EPI_FAILURE);
    new_val->file = value;
    new_val->next = (*list);
    (*list) = new_val;
}

void pull_list(list_t **list)
{
    if (*list != NULL)
        (*list) = (*list)->next;
}

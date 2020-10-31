/*
** EPITECH PROJECT, 2019
** PSU_my_ls_2018
** File description:
** Order
*/

#include "my.h"
#include "my_ls.h"

void swap(list_t* a, list_t* b)
{
    file_t* temp = a->file;

    a->file = b->file;
    b->file = temp;
}

void asc_order(list_t** list)
{
    int swapped = 0;
    list_t* tmp = *list;

    for (int i = 0; tmp; i++) {
        if (tmp->next != NULL && my_strcmp(tmp->file->filename, \
        tmp->next->file->filename) < 0) {
            swap(tmp, tmp->next);
            swapped = 1;
        }
        tmp = tmp->next;
    }
    if (swapped != 0)
        asc_order(list);

}

void order_list(option_t *options, list_t** list)
{
    if (options->r)
        reverse_list(list);
}

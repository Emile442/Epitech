/*
** EPITECH PROJECT, 2019
** 42sh
** File description:
** utils/utils_list
*/

#include "sh.h"

void rotate_list(list_t **list)
{
    data_t* data;

    if (*list != NULL) {
        data = (*list)->data;
        pull_list(list);
        reverse_list(list);
        push_list(list, data);
        reverse_list(list);
    }
}

bool search_list(list_t **list, char* str)
{
    for (int i = 0, count = count_list(list); i != count; i++) {
        if (my_strcmp((*list)->data->key, str))
            return (true);
        rotate_list(list);
    }
    return (false);
}

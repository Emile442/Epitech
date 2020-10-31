/*
** EPITECH PROJECT, 2018
** test_list_count
** File description:
** Test count
*/

#include <criterion/criterion.h>
#include <stddef.h>

#include "my.h"
#include "pushswap.h"

Test(count_list, count_empty_list)
{
    list_t *list= NULL;

    cr_assert_eq(count_list(&list), 0);
    free(list);
}

Test(count_list, count_list_one_item)
{
    list_t *list= NULL;

    push_list(&list, 10);
    cr_assert_eq(count_list(&list), 1);
    free(list);
}

Test(count_list, count_list_two_items)
{
    list_t *list= NULL;

    push_list(&list, 10);
    push_list(&list, 20);
    cr_assert_eq(count_list(&list), 2);
    free(list->next);
    free(list);
}
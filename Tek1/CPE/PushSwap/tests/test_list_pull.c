/*
** EPITECH PROJECT, 2018
** test_list_pull
** File description:
** Test pull
*/

#include <criterion/criterion.h>
#include <stddef.h>

#include "my.h"
#include "pushswap.h"

Test(pull_list, pull_empty_list)
{
    list_t *list = NULL;

    pull_list(&list);
    cr_assert_eq(list, NULL);
}

Test(pull_list, pull_list_with_two_items)
{
    list_t *list= NULL;

    push_list(&list, 10);
    push_list(&list, 20);
    pull_list(&list);
    cr_assert_eq(list->next, NULL);
    free(list);
}

Test(pull_list, pull_list_with_one_items)
{
    list_t *list= NULL;

    push_list(&list, 10);
    pull_list(&list);
    cr_assert_eq(list, NULL);
    free(list);
}
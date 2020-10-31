/*
** EPITECH PROJECT, 2018
** test_list_check
** File description:
** Test Check
*/

#include <criterion/criterion.h>
#include <stddef.h>

#include "my.h"
#include "pushswap.h"

Test(push_list, check_empty_list)
{
    list_t *list = NULL;

    cr_assert_eq(check_already_order(list), true);
}

Test(push_list, check_list_one_item)
{
    list_t *list = NULL;

    push_list(&list, 10);
    cr_assert_eq(check_already_order(list), true);
    free(list);
}

Test(push_list, check_list_two_item_order)
{
    list_t *list = NULL;

    push_list(&list, 10);
    push_list(&list, 9);
    cr_assert_eq(check_already_order(list), true);
    free(list->next);
    free(list);
}

Test(push_list, check_list_two_item_not_order)
{
    list_t *list = NULL;

    push_list(&list, 9);
    push_list(&list, 10);
    cr_assert_eq(check_already_order(list), false);
    free(list->next);
    free(list);
}
/*
** EPITECH PROJECT, 2018
** test_list_push
** File description:
** Test push
*/

#include <criterion/criterion.h>
#include <stddef.h>

#include "my.h"
#include "pushswap.h"

Test(push_list, push_int_to_empty_list)
{
    list_t *list= NULL;

    push_list(&list, 10);
    cr_assert_eq(list->value, 10);
    free(list);
}

Test(push_list, push_int_to_list_get_first)
{
    list_t *list= NULL;

    push_list(&list, 10);
    push_list(&list, 20);
    cr_assert_eq(list->value, 20);
    free(list->next);
    free(list);
}

Test(push_list, push_int_to_list_get_second)
{
    list_t *list= NULL;

    push_list(&list, 10);
    push_list(&list, 20);
    cr_assert_eq(list->next->value, 10);
    free(list->next);
    free(list);
}
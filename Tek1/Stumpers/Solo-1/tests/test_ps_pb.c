/*
** EPITECH PROJECT, 2018
** test_ps_pb
** File description:
** Test PushSwap Pb function
*/

#include <criterion/criterion.h>
#include <stddef.h>

#include "my.h"
#include "pushswap.h"

Test(pb, check_pb_functional)
{
    list_t *list_a = NULL;
    list_t *list_b = NULL;

    push_list(&list_a, 4);
    pb(&list_a, &list_b);
    cr_assert_eq(list_a, NULL);
    cr_assert_eq(list_b->value, 4);
    free(list_a);
    free(list_b);
}

Test(pb, check_pb_two_items_array)
{
    list_t *list_a = NULL;
    list_t *list_b = NULL;

    push_list(&list_a, 4);
    push_list(&list_a, 6);
    reverse_list(&list_a);
    pb(&list_a, &list_b);
    cr_assert_eq(list_a->value, 6);
    cr_assert_eq(list_b->value, 4);
    free(list_a);
    free(list_b);
}

Test(pb, check_pb_b_not_empty)
{
    list_t *list_a = NULL;
    list_t *list_b = NULL;

    push_list(&list_a, 4);
    push_list(&list_a, 6);
    push_list(&list_b, 8);
    reverse_list(&list_a);
    pb(&list_a, &list_b);
    cr_assert_eq(list_a->value, 6);
    cr_assert_eq(list_b->value, 4);
    cr_assert_eq(list_b->next->value, 8);
    free(list_a);
    free(list_b->next);
    free(list_b);
}

Test(pb, check_pb_empty)
{
    list_t *list_a = NULL;
    list_t *list_b = NULL;

    pb(&list_a, &list_b);
    cr_assert_eq(list_a, NULL);
    cr_assert_eq(list_b, NULL);
}
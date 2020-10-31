/*
** EPITECH PROJECT, 2018
** test_ps_pa
** File description:
** Test PushSwap Pa function
*/

#include <criterion/criterion.h>
#include <stddef.h>

#include "my.h"
#include "pushswap.h"

Test(pa, check_pa_functional)
{
    list_t *list_b = NULL;
    list_t *list_a = NULL;

    push_list(&list_b, 4);
    pa(&list_b, &list_a);
    cr_assert_eq(list_b, NULL);
    cr_assert_eq(list_a->value, 4);
    free(list_b);
    free(list_a);
}

Test(pa, check_pa_two_items_array)
{
    list_t *list_b = NULL;
    list_t *list_a = NULL;

    push_list(&list_b, 4);
    push_list(&list_b, 6);
    reverse_list(&list_b);
    pa(&list_b, &list_a);
    cr_assert_eq(list_b->value, 6);
    cr_assert_eq(list_a->value, 4);
    free(list_b);
    free(list_a);
}

Test(pa, check_pa_a_not_empty)
{
    list_t *list_b = NULL;
    list_t *list_a = NULL;

    push_list(&list_b, 4);
    push_list(&list_b, 6);
    push_list(&list_a, 7);
    reverse_list(&list_b);
    pa(&list_b, &list_a);
    cr_assert_eq(list_b->value, 6);
    cr_assert_eq(list_a->value, 4);
    cr_assert_eq(list_a->next->value, 7);
    free(list_b);
    free(list_a->next);
    free(list_a);
}

Test(pa, check_pa_empty)
{
    list_t *list_b = NULL;
    list_t *list_a = NULL;

    pa(&list_b, &list_a);
    cr_assert_eq(list_b, NULL);
    cr_assert_eq(list_a, NULL);
}
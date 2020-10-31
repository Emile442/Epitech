/*
** EPITECH PROJECT, 2018
** test_ps_ra
** File description:
** Test PushSwap Ra function
*/

#include <criterion/criterion.h>
#include <stddef.h>

#include "my.h"
#include "pushswap.h"

Test(ra, check_ra_medium)
{
    list_t *list = NULL;

    push_list(&list, 6);
    push_list(&list, 2);
    push_list(&list, 5);
    push_list(&list, 9);
    reverse_list(&list);
    ra(&list);
    cr_assert_eq(list->value, 2);
    cr_assert_eq(list->next->value, 5);
    cr_assert_eq(list->next->next->value, 9);
    cr_assert_eq(list->next->next->next->value, 6);
    free(list->next->next->next);
    free(list->next->next);
    free(list->next);
    free(list);
}

Test(ra, check_ra_easy)
{
    list_t *list = NULL;

    push_list(&list, 6);
    push_list(&list, 9);
    reverse_list(&list);
    ra(&list);
    cr_assert_eq(list->value, 9);
    cr_assert_eq(list->next->value, 6);
    free(list->next);
    free(list);
}

Test(ra, check_ra_special_case)
{
    list_t *list = NULL;

    push_list(&list, 6);
    reverse_list(&list);
    ra(&list);
    cr_assert_eq(list->value, 6);
    free(list);
}

Test(ra, check_ra_empty)
{
    list_t *list = NULL;

    ra(&list);
    cr_assert_eq(list, NULL);
}
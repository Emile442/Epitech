/*
** EPITECH PROJECT, 2018
** test_list_reverse
** File description:
** Test reverse
*/

#include <criterion/criterion.h>
#include <stddef.h>

#include "my.h"
#include "pushswap.h"

Test(reverse_list, reverse_empty_list)
{
    list_t *list= NULL;

    reverse_list(&list);
    cr_assert_eq(list, NULL);
    free(list);
}

Test(reverse_list, reverse_list_one_item)
{
    list_t *list= NULL;

    push_list(&list, 10);
    reverse_list(&list);
    cr_assert_eq(list->value, 10);
    free(list);
}

Test(reverse_list, reverse_list_two_item)
{
    list_t *list= NULL;

    push_list(&list, 10);
    push_list(&list, 20);
    reverse_list(&list);
    cr_assert_eq(list->value, 10);
    free(list->next);
    free(list);
}
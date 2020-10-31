/*
** EPITECH PROJECT, 2018
** test_list_smaller
** File description:
** Test Liste Found the smaller
*/

#include <criterion/criterion.h>
#include <stddef.h>

#include "my.h"
#include "pushswap.h"

Test(found_the_smaller, positive_number)
{
    list_t *list= NULL;

    push_list(&list, 2);
    push_list(&list, 8);
    push_list(&list, 40);
    push_list(&list, 1);
    push_list(&list, 489);
    cr_assert_eq(found_the_smaller(list), 1);
}

Test(found_the_smaller, negative_number)
{
    list_t *list= NULL;

    push_list(&list, -987);
    push_list(&list, -67);
    push_list(&list, -7);
    push_list(&list, -139);
    push_list(&list, -19);
    cr_assert_eq(found_the_smaller(list), -987);
}

Test(found_the_smaller, negative_positive_number)
{
    list_t *list= NULL;

    push_list(&list, 987);
    push_list(&list, -67);
    push_list(&list, 2);
    push_list(&list, 139);
    push_list(&list, -19);
    cr_assert_eq(found_the_smaller(list), -67);
}
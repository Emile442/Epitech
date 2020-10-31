/*
** EPITECH PROJECT, 2020
** cpp_d03_2019
** File description:
** Ex09
*/

#include <criterion/criterion.h>
#include "../string.h"

Test(empty, empty)
{
    string_t s;
    char* expected = NULL;
    int tmp;

    string_init(&s, expected);
    tmp = s.empty(&s);
    cr_assert_eq(tmp, 1);
}

Test(empty, not_empty)
{
    string_t s;
    char* expected = "Hello World";
    int tmp;

    string_init(&s, expected);
    tmp = s.empty(&s);
    cr_assert_eq(tmp, 0);
}

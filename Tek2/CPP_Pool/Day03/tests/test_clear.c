/*
** EPITECH PROJECT, 2020
** cpp_d03_2019
** File description:
** Ex04
*/

#include <criterion/criterion.h>
#include "../string.h"

Test(clear, good_clear)
{
    string_t s;
    char* expected = "Hello World";

    string_init(&s, expected);
    cr_assert_str_eq(s.str, expected);
    s.clear(&s);
    cr_assert_str_empty(s.str);
}

Test(clear, null)
{
    string_t s;
    char* expected = NULL;

    string_init(&s, expected);
    s.clear(&s);
    cr_assert_null(s.str);
}

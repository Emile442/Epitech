/*
** EPITECH PROJECT, 2020
** cpp_d03_2019
** File description:
** Ex02
*/

#include <criterion/criterion.h>
#include "../string.h"

Test(append_s, good_append)
{
    string_t s;
    string_t s2;
    char* expected = "Hello World";
    char* expected_f = "Hello WorldHello World";

    string_init(&s, expected);
    string_init(&s2, expected);
    cr_assert_str_eq(s.str, expected);
    s2.append_s(&s2, &s);
    cr_assert_str_eq(s2.str, expected_f);
}

Test(append_c, good_append)
{
    string_t s;
    char* expected = "Hello World";
    char* expected_f = "Hello WorldHello World";

    string_init(&s, expected);
    s.append_c(&s, expected);
    cr_assert_str_eq(s.str, expected_f);
}

Test(append_c, null_str_str)
{
    string_t s;
    char* expected = "Hello World";

    string_init(&s, NULL);
    s.append_c(&s, expected);
    cr_assert(s.str == NULL);
}

Test(append_c, null_str)
{
    string_t s;
    char* expected = "Hello World";

    string_init(&s, expected);
    s.append_c(&s, NULL);
    cr_assert_str_eq(s.str, expected);
}

Test(append_s, null_str)
{
    string_t s;
    string_t s2;
    char* expected = "Hello World";

    string_init(&s, NULL);
    string_init(&s2, expected);
    s2.append_s(&s2, &s);
    cr_assert_str_eq(s2.str, expected);
}

/*
** EPITECH PROJECT, 2020
** cpp_d03_2019
** File description:
** Ex11
*/

#include <criterion/criterion.h>
#include "../string.h"

Test(assert_s, good_insert)
{
    string_t s;
    string_t s2;
    char* base = "Hello World";
    char* expected = "HelloHello World World";

    string_init(&s, base);
    string_init(&s2, base);
    s2.insert_s(&s2, 5, &s);
    cr_assert_str_eq(s2.str, expected);
}

Test(assert_c, good_insert)
{
    string_t s;
    char* base = "Hello World";
    char* expected = "HelloHello World World";

    string_init(&s, base);
    s.insert_c(&s, 5, base);
    cr_assert_str_eq(s.str, expected);
}

Test(assert_s, empty_str)
{
    string_t s;
    string_t s2;
    char* base = NULL;

    string_init(&s, base);
    string_init(&s2, base);
    s2.insert_s(&s2, 5, &s);
    cr_assert_null(s2.str);
}

Test(assert_c, empty_str)
{
    string_t s;
    char* base = NULL;

    string_init(&s, base);
    s.insert_c(&s, 5, base);
    cr_assert_null(s.str);
}
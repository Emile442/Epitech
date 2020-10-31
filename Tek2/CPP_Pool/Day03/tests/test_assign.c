/*
** EPITECH PROJECT, 2020
** cpp_d03_2019
** File description:
** Ex01
*/

#include <criterion/criterion.h>
#include "../string.h"

Test(assign_s, good_assign)
{
    string_t s;
    string_t s2;
    char* expected = "Hello World";

    string_init(&s, expected);
    string_init(&s2, NULL);
    cr_assert_str_eq(s.str, expected);
    s2.assign_s(&s2, &s);
    cr_assert_str_eq(s2.str, s.str);
}

Test(assign_c, good_assign)
{
    string_t s;
    string_t s2;
    char* expected = "Hello World";

    string_init(&s, expected);
    string_init(&s2, NULL);
    cr_assert_str_eq(s.str, expected);
    s2.assign_c(&s2, s.str);
    cr_assert_str_eq(s2.str, s.str);
}

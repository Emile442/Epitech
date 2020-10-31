/*
** EPITECH PROJECT, 2020
** cpp_d03_2019
** File description:
** Ex08
*/

#include <criterion/criterion.h>
#include "../string.h"

Test(c_str, good_str)
{
    string_t s;
    char* expected = "Hello World";
    const char* rt;


    string_init(&s, expected);
    rt = s.c_str(&s);
    cr_assert_str_eq(rt, s.str);
}

Test(c_str, empty_str)
{
    string_t s;
    const char* rt;

    string_init(&s, NULL);
    rt = s.c_str(&s);
    cr_assert_null(rt);
}

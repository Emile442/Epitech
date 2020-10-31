/*
** EPITECH PROJECT, 2020
** cpp_d03_2019
** File description:
** Ex00
*/

#include <criterion/criterion.h>
#include "../string.h"

Test(string_init, good_init)
{
    string_t s;
    char* expected = "Hello World";

    string_init(&s, expected);
    cr_assert_str_eq(s.str, expected);
}

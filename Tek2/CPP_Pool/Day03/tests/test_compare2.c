/*
** EPITECH PROJECT, 2020
** cpp_d03_2019
** File description:
** Ex06
*/

#include <criterion/criterion.h>
#include "../string.h"

Test(compare_c, str_null)
{
    string_t s;
    char* expected = "Hello World";

    string_init(&s, expected);
    cr_assert(s.compare_c(&s, NULL) == -1);
}

Test(compare_c, str_str_null)
{
    string_t s;
    char* expected = NULL;

    string_init(&s, expected);
    cr_assert(s.compare_c(&s, expected) == -1);
}

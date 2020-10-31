/*
** EPITECH PROJECT, 2020
** cpp_d03_2019
** File description:
** Ex12
*/

#include <criterion/criterion.h>
#include "../string.h"

Test(to_int, good_int)
{
    string_t s;
    char* base = "1245";
    int expected = 1245;

    string_init(&s, base);
    cr_assert(s.to_int(&s) == expected);
}

Test(to_int, str_null)
{
    string_t s;
    char* base = NULL;
    int expected = 0;

    string_init(&s, base);
    cr_assert(s.to_int(&s) == expected);
}
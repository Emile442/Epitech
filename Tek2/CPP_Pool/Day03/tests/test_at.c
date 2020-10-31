/*
** EPITECH PROJECT, 2020
** cpp_d03_2019
** File description:
** Ex03
*/

#include <criterion/criterion.h>
#include "../string.h"

Test(at, good_c)
{
    string_t s;
    char* expected = "Hello World";

    string_init(&s, expected);
    cr_assert(s.at(&s, 1) == 'e');
}

Test(at, out_of_range)
{
    string_t s;
    char* expected = "Hello World";

    string_init(&s, expected);
    cr_assert(s.at(&s, 20) == -1);
}

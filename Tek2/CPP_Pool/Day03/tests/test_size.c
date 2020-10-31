/*
** EPITECH PROJECT, 2020
** cpp_d03_2019
** File description:
** Ex05
*/

#include <criterion/criterion.h>
#include "../string.h"

Test(size, godd_size)
{
    string_t s;
    char* expected = "Hello World";

    string_init(&s, expected);
    cr_assert(s.size(&s) == 11);
}

Test(size, string_null)
{
    string_t s;

    string_init(&s, NULL);
    cr_assert(s.size(&s) == -1);
}

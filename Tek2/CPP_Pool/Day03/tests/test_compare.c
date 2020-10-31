/*
** EPITECH PROJECT, 2020
** cpp_d03_2019
** File description:
** Ex06
*/

#include <criterion/criterion.h>
#include "../string.h"

Test(compare_c, good_compare)
{
    string_t s;
    char* expected = "Hello World";

    string_init(&s, expected);
    cr_assert(s.compare_c(&s, expected) == 0);
}

Test(compare_s, good_compare)
{
    string_t s;
    string_t s2;
    char* expected = "Hello World";

    string_init(&s, expected);
    string_init(&s2, expected);
    cr_assert(s.compare_s(&s, &s2) == 0);
}

Test(compare_c, diff_compare)
{
    string_t s;
    char* expected = "Hello World";
    char* wrong = "Emile";

    string_init(&s, expected);
    cr_assert(s.compare_c(&s, wrong) != 0);
}

Test(compare_s, diff_compare)
{
    string_t s;
    string_t s2;
    char* expected = "Hello World";
    char* wrong = "Emile";

    string_init(&s, expected);
    string_init(&s2, wrong);
    cr_assert(s.compare_s(&s, &s2) != 0);
}

Test(compare_s, str_str_null)
{
    string_t s;
    string_t s2;
    char* expected = "Hello World";

    string_init(&s, expected);
    string_init(&s2, NULL);
    cr_assert(s.compare_s(&s, &s2) == -1);
}

/*
** EPITECH PROJECT, 2020
** cpp_d03_2019
** File description:
** Ex10
*/

#include <criterion/criterion.h>
#include "../string.h"

Test(find_s, find_s_good)
{
    string_t s;
    string_t s2;
    char* expected = "Hello World";
    char* search = "World";
    int tmp;

    string_init(&s, expected);
    string_init(&s2, search);
    tmp = s.find_s(&s, &s2, 0);
    cr_assert_eq(tmp, 6);
}

Test(find_s, not_found)
{
    string_t s;
    string_t s2;
    char* expected = "Hello World";
    char* search = "World";
    int tmp;

    string_init(&s, expected);
    string_init(&s2, search);
    tmp = s.find_s(&s, &s2, 8);
    cr_assert_eq(tmp, -1);
}

Test(find_s, out_of_range_pos)
{
    string_t s;
    string_t s2;
    char* expected = "Hello World";
    char* search = "World";
    int tmp;

    string_init(&s, expected);
    string_init(&s2, search);
    tmp = s.find_s(&s, &s2, 2000);
    cr_assert_eq(tmp, -1);
}

Test(find_s, out_of_range_str)
{
    string_t s;
    string_t s2;
    char* expected = "Hello World";
    char* search = "hjkdiheiuhuheuhuiheuiu";
    int tmp;

    string_init(&s, expected);
    string_init(&s2, search);
    tmp = s.find_s(&s, &s2, 4);
    cr_assert_eq(tmp, -1);
}

Test(find_s, nul_str)
{
    string_t s;
    string_t s2;
    char* expected = "Hello World";
    char* search = NULL;
    int tmp;

    string_init(&s, expected);
    string_init(&s2, search);
    tmp = s.find_s(&s, &s2, 4);
    cr_assert_eq(tmp, -1);
}

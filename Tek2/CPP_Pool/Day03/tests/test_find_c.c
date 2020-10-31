/*
** EPITECH PROJECT, 2020
** cpp_d03_2019
** File description:
** Ex10
*/

#include <criterion/criterion.h>
#include "../string.h"

Test(find_c, find_c_good)
{
    string_t s;
    char* expected = "Hello World";
    char* search = "World";
    int tmp;

    string_init(&s, expected);
    tmp = s.find_c(&s, search, 0);
    cr_assert_eq(tmp, 6);
}

Test(find_c, not_found)
{
    string_t s;
    char* expected = "Hello World";
    char* search = "World";
    int tmp;

    string_init(&s, expected);
    tmp = s.find_c(&s, search, 8);
    cr_assert_eq(tmp, -1);
}

Test(find_c, out_of_range_pos)
{
    string_t s;
    char* expected = "Hello World";
    char* search = "World";
    int tmp;

    string_init(&s, expected);
    tmp = s.find_c(&s, search, 2000);
    cr_assert_eq(tmp, -1);
}

Test(find_c, out_of_range_str)
{
    string_t s;
    char* expected = "Hello World";
    char* search = "hjkdiheiuhuheuhuiheuiu";
    int tmp;

    string_init(&s, expected);
    tmp = s.find_c(&s, search, 4);
    cr_assert_eq(tmp, -1);
}

Test(find_c, nul_str)
{
    string_t s;
    char* expected = "Hello World";
    char* search = NULL;
    int tmp;

    string_init(&s, expected);
    tmp = s.find_c(&s, search, 4);
    cr_assert_eq(tmp, -1);
}

/*
** EPITECH PROJECT, 2020
** cpp_d09_2019
** File description:
** ex01_tests
*/

#include <criterion/criterion.h>

#include <string>
#include <ostream>
#include <iostream>

#include "ex01.hpp"

Test(ex01, compare_char)
{
    const char* a = "a";
    const char* b = "z";

    cr_assert(::compare(a, a) == 0);
    cr_assert(::compare(a, b) == -1);
    cr_assert(::compare(b, a) == 1);
}

Test(ex01, compare_int) 
{
    int a = 3;
    int b = 9;

    cr_assert(::compare(a, a) == 0);
    cr_assert(::compare(a, b) == -1);
    cr_assert(::compare(b, a) == 1);
}
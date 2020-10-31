/*
** EPITECH PROJECT, 2020
** cpp_rush1_2019
** File description:
** Char Operator
*/

#include <criterion/criterion.h>

#include <stdio.h>

#include "../new.h"
#include "../char.h"

Test(Char_add, Char)
{
    Object  *c1 = new(Char, 65);
    Object  *c2 = new(Char, 1);

    cr_assert_str_eq(str(addition(c1, c2)), "<Char (B)>");
}

Test(Char_sub, Char)
{
    Object  *c1 = new(Char, 69);
    Object  *c2 = new(Char, 3);

    cr_assert_str_eq(str(subtraction(c1, c2)), "<Char (B)>");
}

Test(Char_mul, Char)
{
    Object  *c1 = new(Char, 61);
    Object  *c2 = new(Char, 2);

    cr_assert_str_eq(str(multiplication(c1, c2)), "<Char (z)>");
}

Test(Char_div, Char)
{
    Object  *c1 = new(Char, 122);
    Object  *c2 = new(Char, 2);

    cr_assert_str_eq(str(division(c1, c2)), "<Char (=)>");
}


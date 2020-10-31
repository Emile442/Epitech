/*
** EPITECH PROJECT, 2020
** cpp_rush1_2019
** File description:
** Int Operator
*/

#include <criterion/criterion.h>

#include <stdio.h>

#include "../new.h"
#include "../int.h"

Test(Int_add, Int)
{
    Object  *i1 = new(Int, 0);
    Object  *i2 = new(Int, 4);

    cr_assert_str_eq(str(addition(i1, i2)), "<Int (4)>");
}

Test(Int_sub, Int)
{
    Object  *i1 = new(Int, 9);
    Object  *i2 = new(Int, 4);

    cr_assert_str_eq(str(subtraction(i1, i2)), "<Int (5)>");
}

Test(Int_mul, Int)
{
    Object  *i1 = new(Int, 9);
    Object  *i2 = new(Int, 4);

    cr_assert_str_eq(str(multiplication(i1, i2)), "<Int (36)>");
}

Test(Int_div, Int)
{
    Object  *i1 = new(Int, 9);
    Object  *i2 = new(Int, 4);

    cr_assert_str_eq(str(division(i1, i2)), "<Int (2)>");
}


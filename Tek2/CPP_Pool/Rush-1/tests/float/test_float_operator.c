/*
** EPITECH PROJECT, 2020
** cpp_rush1_2019
** File description:
** Float Operator
*/

#include <criterion/criterion.h>

#include <stdio.h>

#include "../new.h"
#include "../float.h"

Test(Float_add, Float)
{
    Object  *f1 = new(Float, 3.4);
    Object  *f2 = new(Float, 4.9);

    cr_assert_str_eq(str(addition(f1, f2)), "<Float (8.300000)>");
}

Test(Float_sub, Float)
{
    Object  *f1 = new(Float, 3.4);
    Object  *f2 = new(Float, 4.9);

    cr_assert_str_eq(str(subtraction(f1, f2)), "<Float (-1.500000)>");
}

Test(Float_mul, Float)
{
    Object  *f1 = new(Float, 3.4);
    Object  *f2 = new(Float, 4.9);

    cr_assert_str_eq(str(multiplication(f1, f2)), "<Float (16.660000)>");
}

Test(Float_div, Float)
{
    Object  *f1 = new(Float, 3.4);
    Object  *f2 = new(Float, 4.9);

    cr_assert_str_eq(str(division(f1, f2)), "<Float (0.693878)>");
}

Test(Float_sub, Zero_Display)
{
    Object  *f1 = new(Float, 0.875821);
    Object  *f2 = new(Float, 0.875821);

    cr_assert_str_eq(str(subtraction(f1, f2)), "<Float (0.000000)>");
}

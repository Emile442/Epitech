/*
** EPITECH PROJECT, 2020
** cpp_rush1_2019
** File description:
** Float Comprator
*/

#include <criterion/criterion.h>

#include <stdio.h>

#include "../new.h"
#include "../float.h"

Test(Float_eq, Float)
{
    Object  *f1 = new(Float, 1.8);
    Object  *f2 = new(Float, 4.3);
    Object  *f3 = new(Float, 4.3);

    cr_assert(eq(f1, f2) == false);
    cr_assert(eq(f2, f3) == true);
}

Test(Float_gt, Float)
{
    Object  *f1 = new(Float, 1.8);
    Object  *f2 = new(Float, 4.9);
    Object  *f3 = new(Float, 5.1);

    cr_assert(gt(f1, f2) == false);
    cr_assert(gt(f3, f2) == true);
}

Test(Float_lt, Float)
{
    Object  *f1 = new(Float, 1.8);
    Object  *f2 = new(Float, 4.9);
    Object  *f3 = new(Float, 5.1);

    cr_assert(lt(f1, f2) == true);
    cr_assert(lt(f3, f2) == false);
}
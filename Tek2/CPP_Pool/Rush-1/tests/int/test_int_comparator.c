/*
** EPITECH PROJECT, 2020
** cpp_rush1_2019
** File description:
** Int Comprator
*/

#include <criterion/criterion.h>

#include <stdio.h>

#include "../new.h"
#include "../int.h"

Test(Int_eq, Int)
{
    Object  *i1 = new(Int, 0);
    Object  *i2 = new(Int, 4);
    Object  *i3 = new(Int, 4);

    cr_assert(eq(i1, i2) == false);
    cr_assert(eq(i2, i3) == true);
}

Test(Int_gt, Int)
{
    Object  *i1 = new(Int, 0);
    Object  *i2 = new(Int, 4);
    Object  *i3 = new(Int, 6);

    cr_assert(gt(i1, i2) == false);
    cr_assert(gt(i3, i2) == true);
}

Test(Int_lt, Int)
{
    Object  *i1 = new(Int, 0);
    Object  *i2 = new(Int, 4);
    Object  *i3 = new(Int, 6);

    cr_assert(lt(i1, i2) == true);
    cr_assert(lt(i3, i2) == false);
}
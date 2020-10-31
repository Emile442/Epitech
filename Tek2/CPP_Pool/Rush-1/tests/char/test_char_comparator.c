/*
** EPITECH PROJECT, 2020
** cpp_rush1_2019
** File description:
** Char Comprator
*/

#include <criterion/criterion.h>

#include <stdio.h>

#include "../new.h"
#include "../char.h"

Test(Char_eq, Char)
{
    Object  *c1 = new(Char, 65);
    Object  *c2 = new(Char, 66);
    Object  *c3 = new(Char, 66);

    cr_assert(eq(c1, c2) == false);
    cr_assert(eq(c2, c3) == true);
}

Test(Char_gt, Char)
{
    Object  *c1 = new(Char, 25);
    Object  *c2 = new(Char, 65);
    Object  *c3 = new(Char, 66);

    cr_assert(gt(c1, c2) == false);
    cr_assert(gt(c3, c2) == true);
}

Test(Char_lt, Char)
{
    Object  *c1 = new(Char, 25);
    Object  *c2 = new(Char, 65);
    Object  *c3 = new(Char, 66);

    cr_assert(lt(c1, c2) == true);
    cr_assert(lt(c3, c2) == false);
}
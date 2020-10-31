/*
** EPITECH PROJECT, 2020
** cpp_rush1_2019
** File description:
** Point Operator
*/

#include <criterion/criterion.h>

#include <stdio.h>

#include "../new.h"
#include "../point.h"

Test(Point_add, Point)
{
    Object  *p1 = new(Point, 0, 1);
    Object  *p2 = new(Point, 4, 6);

    cr_assert_str_eq(str(addition(p1, p2)), "<Point (4, 7)>");
}

Test(Point_sub, Point)
{
    Object  *p1 = new(Point, 9, 8);
    Object  *p2 = new(Point, 4, 6);

    cr_assert_str_eq(str(subtraction(p1, p2)), "<Point (5, 2)>");
}
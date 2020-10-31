/*
** EPITECH PROJECT, 2020
** cpp_rush1_2019
** File description:
** Point
*/

#include <criterion/criterion.h>

#include <stdio.h>

#include "../new.h"
#include "../point.h"

Test(new, Point)
{
    Object  *point = new(Point, 0, 1);

    cr_assert_str_eq(str(point), "<Point (0, 1)>");
}

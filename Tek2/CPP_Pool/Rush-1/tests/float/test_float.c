/*
** EPITECH PROJECT, 2020
** cpp_rush1_2019
** File description:
** Float
*/

#include <criterion/criterion.h>

#include <stdio.h>

#include "../new.h"
#include "../float.h"

Test(new, Float)
{
    Object  *float_number = new(Float, 3.8);

    cr_assert_str_eq(str(float_number), "<Float (3.800000)>");
}
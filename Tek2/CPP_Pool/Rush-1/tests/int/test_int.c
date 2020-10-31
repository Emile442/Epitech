/*
** EPITECH PROJECT, 2020
** cpp_rush1_2019
** File description:
** Int
*/

#include <criterion/criterion.h>

#include <stdio.h>

#include "../new.h"
#include "../int.h"

Test(new, Int)
{
    Object  *integer = new(Int, 3);

    cr_assert_str_eq(str(integer), "<Int (3)>");
}
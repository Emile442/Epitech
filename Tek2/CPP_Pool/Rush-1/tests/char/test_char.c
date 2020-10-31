/*
** EPITECH PROJECT, 2020
** cpp_rush1_2019
** File description:
** Char
*/

#include <criterion/criterion.h>

#include <stdio.h>

#include "../new.h"
#include "../char.h"

Test(new, Char)
{
    Object *c = new(Char, 101);

    cr_assert_str_eq(str(c), "<Char (e)>");
}
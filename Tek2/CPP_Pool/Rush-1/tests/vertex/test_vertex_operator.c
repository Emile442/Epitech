/*
** EPITECH PROJECT, 2020
** cpp_rush1_2019
** File description:
** Vertex Operator
*/

#include <criterion/criterion.h>

#include <stdio.h>

#include "../new.h"
#include "../vertex.h"

Test(Vertex_add, Vertex)
{
    Object  *v1 = new(Vertex, 0, 1, 2);
    Object  *v2 = new(Vertex, 4, 6, 9);

    cr_assert_str_eq(str(addition(v1, v2)), "<Vertex (4, 7, 11)>");
}

Test(Vertex_sub, Vertex)
{
    Object  *v1 = new(Vertex, 9, 8, 15);
    Object  *v2 = new(Vertex, 4, 6, 9);

    cr_assert_str_eq(str(subtraction(v1, v2)), "<Vertex (5, 2, 6)>");
}
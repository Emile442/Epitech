/*
** EPITECH PROJECT, 2020
** cpp_rush1_2019
** File description:
** Vertex
*/

#include <criterion/criterion.h>

#include <stdio.h>

#include "../new.h"
#include "../vertex.h"

Test(new, Vertex)
{
    Object  *vertex = new(Vertex, 0, 1, 2);

    cr_assert_str_eq(str(vertex), "<Vertex (0, 1, 2)>");
}

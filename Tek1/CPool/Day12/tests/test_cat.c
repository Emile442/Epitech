/*
** EPITECH PROJECT, 2018
** test_cat
** File description:
** Test cat
*/

#include <criterion/criterion.h>
#include "my.h"

int cat(int argc, char const **argv);

Test(cat, cat_missing_argument)
{
    char $tmp[];

    cr_assert_eq(cat(1, tmp), 84);
}
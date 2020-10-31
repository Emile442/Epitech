/*
** EPITECH PROJECT, 2018
** test_rush2
** File description:
** Test rush2.C
*/

#include <criterion/criterion.h>
#include "my.h"

int count_letter(const char *str, char c);

Test(count_letter, tes)
{
    char *str = "Je suis un test";
    char c = 's';

    my_put_nbr(15454);

    cr_assert_eq(count_letter(str, c), 3);
}
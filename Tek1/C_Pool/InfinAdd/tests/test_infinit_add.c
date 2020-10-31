/*
** EPITECH PROJECT, 2018
** infinit_add
** File description:
** Test infinit add
*/

#include "my.h"
#include <criterion/criterion.h>

char *infinit_add(char *nb1, char *nb2);

Test(infinit_add, single_number)
{
    char *nb1 = "10";
    char *nb2 = "20";
    char *tmp = infinit_add(nb1, nb2);

    cr_assert_eq(tmp, "30");
}

Test(infinit_add, single_number)
{
    char *nb1 = "-10";
    char *nb2 = "-20";
    char *tmp = infinit_add(nb1, nb2);

    cr_assert_eq(tmp, "-30");
}

Test(infinit_add, single_number)
{
    char *nb1 = "20";
    char *nb2 = "-10";
    char *tmp = infinit_add(nb1, nb2);

    cr_assert_eq(tmp, "20");
}
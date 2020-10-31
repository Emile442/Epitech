/*
** EPITECH PROJECT, 2018
** test_nmatch
** File description:
** Tets nmatch
*/

#include "my.h"
#include <criterion/criterion.h>

int nmatch(char const *s1, char const *s2);

Test(nmatch, one_occurrence)
{
    char *val1 = "helloworld";
    char *val2 = "*h*";

    cr_assert_eq(nmatch(val1, val2) , 1);
}

Test(nmatch, pattern_one_occurrence)
{
    char *val1 = "helloworld";
    char *val2 = "*ll*";

    cr_assert_eq(nmatch(val1, val2) , 1);
}

Test(nmatch, three_occurrence)
{
    char *val1 = "helloworld";
    char *val2 = "*l*";

    cr_assert_eq(nmatch(val1, val2) , 3);
}
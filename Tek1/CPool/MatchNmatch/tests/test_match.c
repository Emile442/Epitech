/*
** EPITECH PROJECT, 2018
** test_match
** File description:
** Tets match
*/

#include "my.h"
#include <criterion/criterion.h>

int match(char const *s1, char const *s2);

Test(match, match_exact_found)
{
    char *val1 = "Test";
    char *val2 = "Test";

    cr_assert_eq(match(val1, val2), 1);
}

Test(match, match_not_found)
{
    char *val1 = "Test";
    char *val2 = "HelloWorld";

    cr_assert_eq(match(val1, val2), 0);
}

Test(match, match_not_found_sensitivecase)
{
    char *val1 = "Test";
    char *val2 = "test";

    cr_assert_eq(match(val1, val2), 0);
}

Test(match, match_found_with_partial_string)
{
    char *val1 = "Test";
    char *val2 = "Tes*";

    cr_assert_eq(match(val1, val2), 1);
}

Test(match, match_found_with_partial_two_char)
{
    char *val1 = "Test";
    char *val2 = "Te*";

    cr_assert_eq(match(val1, val2), 1);
}
/*
** EPITECH PROJECT, 2018
** test_my_revstr
** File description:
** Test strn
*/

#include <criterion/criterion.h>

int my_strncmp(const char *s1, const char *s2, int n);

Test(my_revstr, return_value_is_reversed)
{
    cr_assert_eq(my_strncmp("Hello", "el", 3), 1);
}
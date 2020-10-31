/*
** EPITECH PROJECT, 2018
** test_my_strdup
** File description:
** Test my_strdup
*/

#include <criterion/criterion.h>

char *my_strdup(char const *src);

Test(my_strdup, copy_string_and_return)
{
    char const *tmp = "Test";

    cr_assert_str_eq(my_strdup(tmp), "Test");
}
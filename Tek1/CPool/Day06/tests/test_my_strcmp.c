/*
** EPITECH PROJECT, 2018
** strcmp
** File description:
** Test strcmp
*/

#include <criterion/criterion.h>

int my_strcmp(char *s1, char*s2);

Test(my_strcmp, test_function_equal_zero)
{
    cr_assert_eq(my_strcmp("Hello", "Hello") , 0);
}

Test(my_strcmp, test_function_sup)
{
    cr_assert_eq(my_strcmp("ABcef", "ACef") , -1);
}
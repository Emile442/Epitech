/*
** EPITECH PROJECT, 2018
** test_my_strncpy
** File description:
** Test my_strstr
*/

#include <criterion/criterion.h>

char *my_strstr(char *str, char const *to_find);

Test(my_strstr, test_extact_str)
{
    cr_assert_str_eq(my_strstr("Hello", "llo") , "llo");
}

Test(my_strstr, test_extact_str_longer)
{
    cr_assert_str_eq(my_strstr("HelloWorld", "llo") , "lloWorld");
}

Test(my_strstr, test_extact_str_not_found)
{
    cr_assert_eq(my_strstr("Bonjour", "llo") , NULL);
}

Test(my_strstr, test_extact_str_tromp_not_found)
{
    cr_assert_eq(my_strstr("helol", "llo") , NULL);
}
/*
** EPITECH PROJECT, 2018
** test_my_strncpy
** File description:
** Test my_strncpy
*/

#include <criterion/criterion.h>

char *my_strncpy(char *dest, char *src, int n);

Test(my_strncpy, copy_five_characters_in_empty_array)
{
    char dest[6] = {0};

    my_strncpy(dest, "HelloWorld", 5);
    cr_assert_str_eq(dest , "Hello");
}

Test(my_strncpy, copy_five_characters_in_array_15)
{
    char dest[16] = {0};

    my_strncpy(dest, "HelloWorld", 15);
    cr_assert_str_eq(dest , "HelloWorld");
}

Test(my_strncpy, copy_five_characters_in_array_2)
{
    char dest[6] = {0};

    my_strncpy(dest, "HelloWorld", 2);
    cr_assert_str_eq(dest , "He");
}
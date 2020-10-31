/*
** EPITECH PROJECT, 2018
** test_my_strupcase
** File description:
** Test strupcase
*/

#include<criterion/criterion.h>

char *my_strcpy(char *dest, char const *src);
char *my_strupcase(char *str);

Test(my_strcpy, copy_string_in_empty_array)
{
    char dest[6]= {0};
    
    my_strcpy(dest, "Hello");
    cr_assert_str_eq(my_strupcase("Hello"), "HELLO");
}
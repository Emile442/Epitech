/*
** EPITECH PROJECT, 2018
** test_my_revstr
** File description:
** Test my_revstr
*/

#include <criterion/criterion.h>

char *my_revstr(char *str);

char *my_strcpy(char *dest, char const *src)
{
    for (int i = 0; src[i] != '\0';) {
        dest[i] = src[i];
        i++;
        dest[i + 1] = 0;
    }
    return (dest);
}

Test(my_revstr, return_value_is_reversed)
{
    char dest[6] = {0};

    my_strcpy(dest, "Hello");
    cr_assert_str_eq(my_revstr(dest), "olleH");
}
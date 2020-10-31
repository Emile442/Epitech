/*
** EPITECH PROJECT, 2019
** My library
** File description:
** My put error file
*/

#include <my.h>

int my_put_error(char const *str)
{
    int len;

    len = my_strlen(str);
    if (len != write(2, str, len))
        return (1);
    return (0);
}

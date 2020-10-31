/*
** EPITECH PROJECT, 2018
** my_puterr
** File description:
** display message on error output
*/

#include "my.h"

int my_puterr(char const *err)
{
    write(2, err, my_strlen(err));
    write(2, "\n", 1);
    return (ERROR);
}

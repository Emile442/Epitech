/*
** EPITECH PROJECT, 2019
** My_printf
** File description:
** Print nbr file
*/

#include <my_printf_fct.h>

int print_int(va_list *list)
{
    int nbr = va_arg(*list, int);
    my_put_nbr(nbr);
    return (0);
}

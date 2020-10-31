/*
** EPITECH PROJECT, 2019
** My printf
** File description:
** Print alpha arg file
*/

#include <my_printf_fct.h>

int print_str(va_list *list)
{
    char *str = va_arg(*list, char *);
    my_putstr(str);
    return (0);
}

int print_char(va_list *list)
{
    char c = va_arg(*list, int);
    my_putchar(c);
    return (0);
}

/*
** EPITECH PROJECT, 2018
** my_printf_func
** File description:
** Specific adaptator function for my_printf STR
*/

#include <stdarg.h>
#include <stdlib.h>

void my_putchar(char c);
int my_putstr(char const *str);
int my_put_nbr(int number);
void my_put_addr(int str);
int my_put_unsigned_nbr(unsigned int nbr);

void my_printf_putchar(va_list prms)
{
    my_putchar(va_arg(prms, int));
}

void my_printf_putstr(va_list prms)
{
    my_putstr(va_arg(prms, char*));
}

void my_printf_put_nbr(va_list prms)
{
    my_put_nbr(va_arg(prms, int));
}

void my_printf_put_unsigned_nbr(va_list prms)
{
    my_put_unsigned_nbr(va_arg(prms, int));
}

void my_printf_getaddr(va_list prms)
{
    my_put_addr(va_arg(prms, int));
}
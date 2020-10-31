/*
** EPITECH PROJECT, 2018
** my_printf_func_nbr
** File description:
** Specific adaptator function for my_printf NBR
*/

#include <stdarg.h>
#include <stdlib.h>

int my_put_unsigned_nbr_base(unsigned int nbr, char *base);

void my_printf_octal(va_list prms)
{
    my_put_unsigned_nbr_base(va_arg(prms, int), "01234567");
}

void my_printf_hex(va_list prms)
{
    my_put_unsigned_nbr_base(va_arg(prms, int), "0123456789abcdef");
}

void my_printf_hex_maj(va_list prms)
{
    my_put_unsigned_nbr_base(va_arg(prms, int), "0123456789ABCDEF");
}

void my_printf_bin(va_list prms)
{
    my_put_unsigned_nbr_base(va_arg(prms, int), "01");
}
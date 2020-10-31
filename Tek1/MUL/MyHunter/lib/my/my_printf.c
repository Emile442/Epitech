/*
** EPITECH PROJECT, 2018
** my_printf
** File description:
** PrintF
*/
#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>

void my_putchar(char c);

void my_printf_putchar(va_list prms);
void my_printf_putstr(va_list prms);
void my_printf_put_nbr(va_list prms);
void my_printf_put_unsigned_nbr(va_list prms);
void my_printf_getaddr(va_list prms);
void my_printf_octal(va_list prms);
void my_printf_hex(va_list prms);
void my_printf_hex_maj(va_list prms);
void my_printf_bin(va_list prms);
void my_printf_getaddr(va_list prms);

int flag_nbr(char flag)
{
    int res = -1;
    char* ref = "csiduoxXbp";

    for (int j = 0; ref[j] != 0; j++)
        if (flag == ref[j])
            res = j;
    if (res == -1)
        return (-1);
    return (res);
}

void display(char str, va_list prms)
{
    int pos = flag_nbr(str);
    void (*function_pointers[])(va_list) = {
        my_printf_putchar,
        my_printf_putstr,
        my_printf_put_nbr,
        my_printf_put_nbr,
        my_printf_put_unsigned_nbr,
        my_printf_octal,
        my_printf_hex,
        my_printf_hex_maj,
        my_printf_bin,
        my_printf_getaddr,
        NULL
    };

    if (pos == -1) {
        if ((str >= 97 && str <= 122) || (str >= 65 && str <= 90))
            my_putchar('%');
        my_putchar(str);
    } else
        (*function_pointers[pos])(prms);
}

int my_printf(char *str, ...)
{
    va_list prms;

    va_start(prms, str);
    while (*str) {
        if (*str == '%') {
            str++;
            display(*str, prms);
            str++;
        } else {
            my_putchar(*str);
            str++;
        }
    }
    va_end(prms);
    return (0);
}
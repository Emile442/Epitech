/*
** EPITECH PROJECT, 2019
** My_printf
** File description:
** printf main file
*/

#include <my_printf.h>

const flag_t flag_tab[MAX_FLAG] =
{
    {'i', print_int},
    {'s', print_str},
    {'c', print_char}
};

void use_flag(const char *str, int count, va_list *list)
{
    if (str[count] == '%')
        my_putchar(str[count]);
    for (int i = 0; i < MAX_FLAG; i++) {
        if (str[count] == flag_tab[i].c)
            flag_tab[i].fct(list);
    }
}

int my_printf(const char *str, ...)
{
    va_list list;
    int count = 0;

    va_start(list, str);
    while (str[count]) {
        if (str[count] == '%') {
            count++;
            use_flag(str, count, &list);
        } else
            my_putchar(str[count]);
        count++;
    }
    return (count);
}

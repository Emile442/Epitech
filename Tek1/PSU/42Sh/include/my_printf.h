/*
** EPITECH PROJECT, 2019
** My_printf
** File description:
** Printf header
*/

#ifndef PRINTF_H
# define PRINTF_H

//Include standard libraries
# include <stdarg.h>
# include <my.h>

//Include other my_printf header
# include <my_printf_fct.h>

//Structure
typedef struct flag_s
{
    char c;
    int (*fct)(va_list *list);
} flag_t;

//Flag table define
# define MAX_FLAG 3

//Prototype
int my_printf(const char *str, ...);

#endif

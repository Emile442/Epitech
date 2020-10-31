/*
** EPITECH PROJECT, 2019
** My_printf
** File description:
** Print nbr header
*/

#ifndef PRINT_NBR_H
# define PRINT_NBR_H

//Include standard libraries
# include <stdarg.h>

//Include my library
# include <my.h>

//Prototype
int print_int(va_list *list);
int print_str(va_list *list);
int print_char(va_list *list);

#endif

/*
** EPITECH PROJECT, 2018
** my.h
** File description:
** lib header
*/

#ifndef MY_H
# define MY_H

//Include more complex functions
# include <my_printf.h>
# include <get_next_line.h>

//Include standard libraries
# include <stdlib.h>

//Transform char* in var
int my_get_nbr(char const *str);
char **my_str_to_word_array(char *str);
char *my_strlowercase(char *str);
char *my_struppercase(char *str);

//Get info
int my_strlen(char const *str);
int my_strarray_len(char * const *array);
int my_str_isnum(char const *str);
int my_str_isposnum(char const *str);
int my_strcmp(char const *str_1, char const *str_2);
int my_strncmp(char const *str_1, char const *str_2, int n);
int my_str_isalpha(char const *str);
int my_str_isalphanum(char const *str);
int my_str_isdouble(char const *str);

//Output
int my_put_error(char const *str);
int my_putchar(char c);
int my_put_nbr(int nb);
int my_putstr(char const *str);

//Other
char *my_strcat(char *dest, char *str);
char *my_strcpy(char *str);
char *my_strncpy(char *str, int nb);
void my_swap(int *a, int *b);
char **my_strarraycpy(char **array);

#endif

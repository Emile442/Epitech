/*
** EPITECH PROJECT, 2018
** my.h
** File description:
** my
*/


#ifndef MY_H_
#define MY_H_

#define ERROR (84)
#define SUCCESS (0)
#define ERROR_MALLOC "Malloc Error"

#include <unistd.h>
#include <stdlib.h>
#include <stdbool.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>

char *my_strset(int size, char c);
int my_puterr(char const *err);
struct info_param *my_params_to_array(int ac, char **av);
int my_show_param_array(struct info_param *par);
char **my_str_to_word_array(char const *str, char const *separators);
int my_show_word_array(char * const *tab);
char *my_strdup(char const *src);
int my_compute_power_rec(int nb, int p);
int my_compute_square_root(int nb);
int my_find_prime_sup(int nb);
int count_neg(char const *str);
bool is_digit(char c);
int my_getnbr(char const *str);
int my_isneg(int n);
int my_is_prime(int nb);
void my_putchar(char c);
int nb_size(int nb);
int reduce(int temp, int size);
int my_put_nbr(int nb);
int my_putstr(char const *str);
char *my_revstr(char *str);
int my_showmem(char const *str, int size);
int my_showstr(char const *str);
int is_sorted(int *array, int size);
void my_sort_int_array(int *array, int size);
int is_lowcase(char c);
int is_upcase(char c);
int is_alpha_num(char c);
int is_first(char *str, int i);
char *my_strcapitalize(char *str);
char *my_strcat(char *dest, char const *src);
int my_strcmp(char const *str1, char const *str2);
char *my_strcpy(char *dest, char const *src);
bool is_alpha(char c);
int my_str_isalpha(char const *str);
int my_str_islower(char const *str);
int my_str_isnum(char const *str);
int my_str_isprintable(char const *str);
int my_str_isupper(char const *str);
int my_strlen(char const *str);
char *my_strlowcase(char *str);
char *my_strncat(char *dest, char const *src, int nb);
int my_strncmp(char const *s1, char const *s2, int n);
char *my_strncpy(char *dest, char const *src, int n);
char *my_strstr(char *str, char const *to_find);
char *my_strupcase(char *str);
void my_swap(int *a, int *b);
char **my_realloc(char **old_array, int new_size);
int my_str_isnum_pars(char const *str, char c);
int detec_char(char *str, char c);
char **my_str_to_word_array_bis(char split, char *str);

#endif

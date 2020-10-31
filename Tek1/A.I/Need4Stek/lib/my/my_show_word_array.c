/*
** EPITECH PROJECT, 2018
** my_show_word_array.c
** File description:
** display  array
*/

#include "my.h"

int my_show_word_array(char * const *tab)
{
    int i = 0;

    for (; tab[i]; i++) {
        my_putstr(tab[i]);
        my_putchar('\n');
    }
    return (0);
}

/*
** EPITECH PROJECT, 2018
** my_show_word_array
** File description:
** Write a function that displays the content of an array of words
*/

#include "include/my.h"

int my_show_word_array(char * const *tab)
{
    for (int i = 0; tab[i]; i++) {
        if (my_str_isalpha(tab[i])) {
            my_putstr(tab[i]);
            my_putchar('\n');
        }
    }
    return (0);
}

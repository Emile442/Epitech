/*
** EPITECH PROJECT, 2018
** my_sort_word_array
** File description:
** Sort array in ASC mode
*/

#include <stdlib.h>
#include "my.h"
 
int my_array_length(char **tab)
{
    int i = 0;
    
    for (; tab[i]; i++);
    return (i-1);
}
 
void switch_place(char **tab, int i, int j)
{
    char tmp;

    if (my_strcmp(tab[i], tab[j]) > 0) {
        tmp = malloc(sizeof(tab[i]));
        my_strcpy(tmp, tab[i]);
        my_strcpy(tab[i], tab[j]);
        my_strcpy(tab[j], tmp);
    }
    
}
 
char **my_sort_word_array(char **tab)
{
    int length = my_array_length(tab);

    for (int i = 0; i < length; i++)
        for (int j = i; j < length; j++)
            switch_place(tab, i, j);
    return (tab);
}
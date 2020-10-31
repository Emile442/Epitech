/*
** EPITECH PROJECT, 2019
** PSU_navy_2018
** File description:
** print_map
*/

#include "my.h"
#include "navy.h"

void print_map(char** map)
{
    my_printf(" |A B C D E F G H\n");
    my_printf("-+---------------\n");
    for (int i = 0; map[i]; i++) {
        my_printf("%i|", i+1);
        for (int j = 0; map[i][j]; j++)
            my_printf("%c%s", map[i][j], (j != 7) ? " " : "");
        my_putchar(0, '\n');
    }
    my_putchar(0, '\n');
}

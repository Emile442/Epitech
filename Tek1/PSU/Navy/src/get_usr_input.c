/*
** EPITECH PROJECT, 2019
** get usr input
** File description:
** uses gnl to get usr input
*/

#include "../include/navy.h"
#include <stdlib.h>

int input_is_valid(char *input)
{
    if (my_strlen(input) != 2 ||
        input[0] < 'A' || input[0] > 'H' ||
        input[1] < '1' || input[1] > '8')
        return (0);
    return (1);
}

int get_usr_input(void)
{
    char *input;
    int nbr;

    my_printf("attack: ");
    my_dprintf(0, "\e[3m");
    input = get_next_line(0);
    my_dprintf(0, "\e[0m");
    if (!input)
        return (-1);
    if (!input_is_valid(input)) {
        if (input)
            free(input);
        my_printf("wrong position\n");
        return (get_usr_input());
    }
    nbr = (input[0] - 'A') * 10 + input[1] - '1';
    if (input)
        free(input);
    return (nbr);
}

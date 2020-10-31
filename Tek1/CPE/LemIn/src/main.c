/*
** EPITECH PROJECT, 2019
** main
** File description:
** lemin main
*/

#include "parsing.h"

int main(void)
{
    anthill_t *anthill = get_anthill();

    if (!anthill)
        return (84);
    destroy_anthill(anthill);
    return (0);
}

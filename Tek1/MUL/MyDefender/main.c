/*
** EPITECH PROJECT, 2018
** main
** File description:
** Main
*/

#include "my_defender.h"

int main(int ac, char **av)
{
    window_t *current;

    if (ac == 2 && !my_strcmp(av[1], "-h")) {
        show_help();
        return (0);
    }
    current = init_frame(1920, 1080, 32);
    if (!current->window)
        return (EXIT_FAILURE);
    sfRenderWindow_setFramerateLimit(current->window, 60);
    while (sfRenderWindow_isOpen(current->window)) {
        update_frame(current);
        if (current->exit)
            break;
    }
    destroy(current);
    return (0);
}

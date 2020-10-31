/*
** EPITECH PROJECT, 2018
** main
** File description:
** Main
*/

#include "my.h"
#include "my_runner.h"

bool check_end_map(window_t* current)
{
    map_t *tmp = NULL;

    tmp = current->map;
    while (tmp) {
        if (tmp->value == 1 && tmp->entity->pos.x >= -100) {
            return (false);
        }
        tmp = tmp->next;
    }
    return (true);
}

void print_status(window_t* current)
{
    if (check_end_map(current))
        my_putstr("Vous avez gagné\n");
    else if (current->lives <= 0)
        my_putstr("Vous avez perdu\n");
}

int main(int ac, char **av)
{
    window_t *current;

    if (ac != 2 || !my_strcmp(av[1], "-h")) {
        show_help();
        return (0);
    }
    current = init_frame(1920, 1080, 32, av[1]);
    if (!current->window || current->error)
        return (EXIT_FAILURE);
    while (sfRenderWindow_isOpen(current->window)) {
        event_listener(current);
        game_anim(current);
        sfRenderWindow_display(current->window);
        if (current->lives <= 0 || check_end_map(current))
            break;
    }
    print_status(current);
    game_destroy(current);
    return (0);
}

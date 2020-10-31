/*
** EPITECH PROJECT, 2018
** main
** File description:
** Main File
*/

#include <stddef.h>
#include <stdlib.h>
#include <unistd.h>

#include "my.h"
#include "pushswap.h"

static void add_command(char* command, char* str)
{
    int len_str = my_strlen(str);
    int len_command = my_strlen(command);
    int buffer = 2046;

    for (int i = 0; i < len_str; i++, len_command++)
        command[len_command] = str[i];
    if (len_command == buffer) {
        write(1, command, buffer);
        command = my_memset(command, '\0', buffer);
    }
}

void pre_order(list_t **list_a, list_t **list_b, char* command)
{
    int small;

    while (*list_a) {
        small = found_the_smaller(*list_a);
        while ((*list_a)->value != small) {
            ra(list_a);
            add_command(command, "ra ");
        }
        pb(list_a, list_b);
        add_command(command, "pb ");
    }
}

void order(list_t **list_a, list_t **list_b, char* command)
{
    int count_b;

    count_b = count_list(list_b);
    for (int i = 0; *list_b; i++) {
        pa(list_b, list_a);
        add_command(command, "pa ");
    }
}

void pushswap(int ac, char **av)
{
    list_t *list_a = NULL;
    list_t *list_b = NULL;
    char* command = malloc(sizeof(char) * (2048) + 1);

    for (int i = 0; i < ac - 1; i++)
        push_list(&list_a, my_getnbr(av[i + 1]));
    reverse_list(&list_a);
    if (!check_already_order(list_a)) {
        pre_order(&list_a, &list_b, command);
        order(&list_a, &list_b, command);
    }
    write(1, command, my_strlen(command) - 1);
    my_putchar('\n');
    free(list_a);
    free(list_b);
}

int main(int ac, char **av)
{
    if (ac == 1)
        return (EPI_FAILURE);
    pushswap(ac, av);
    return (0);
}

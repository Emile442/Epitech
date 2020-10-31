/*
** EPITECH PROJECT, 2018
** main
** File description:
** Main
*/

#include <ncurses.h>
#include <stdlib.h>

#include "my.h"
#include "sokoban.h"

int main(int argc, char **argv)
{
    if (argv[1] && !my_strcmp(argv[1], "-h")) {
        my_printf("USAGE\n");
        my_printf("     ./my_sokoban map\n");
        my_printf("DESCRIPTION\n");
        my_printf("     map file representing the warehouse map, ");
        my_printf("containing '#' for walls,\n");
        my_printf("         'P' for the player, 'X' for boxes and 'O' ");
        my_printf(" for storage locations.\n");
        return (0);
    }
    initscr();
    sokoban(argv[1]);
    endwin();
    return (0);
}

/*
** EPITECH PROJECT, 2018
** MAIN
** File description:
** MAIN FILE
*/

#include <unistd.h>
#include <draw_file.h>

int main(int ac, char **av)
{
    if (ac < 2) {
        write(2, "Please specify an image file to open.", 38);
        return (84);
    }
    draw_window(800, 600, 32, av[1]);
    return (0);
}
/*
** EPITECH PROJECT, 2019
** CPE_solostumper_2_2018
** File description:
** main
*/

#include <stdio.h>
#include <stdbool.h>
#include <unistd.h>

#include "my.h"
#include "stumper.h"

int main(int ac, char** av)
{
    if (ac != 3) {
        write(2, "Error: not enough arguments.\n", 29);
        return (84);
    }
    anagram(av[1], av[2]);
    return (0);
}

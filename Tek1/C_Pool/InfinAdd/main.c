/*
** EPITECH PROJECT, 2018
** main
** File description:
** Main of inifinit add
*/

#include "my.h"

char *infinit_add(char *nb1, char *nb2);

int main(int argc, char **argv)
{
    my_putstr(infinit_add(argv[1], argv[2]));
    return (0);
}
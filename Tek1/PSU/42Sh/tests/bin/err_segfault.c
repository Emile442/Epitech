/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2018
** File description:
** segfault
*/

#include <unistd.h>
#include <stdlib.h>

int main(void)
{
    int *i = 0;

    *i = 33;
    return (0);
}

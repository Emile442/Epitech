/*
** EPITECH PROJECT, 2018
** my_find_prime_sup
** File description:
** find next prime nbr
*/

#include "my.h"

int my_find_prime_sup(int nb)
{
    nb++;
    while (1) {
        if (my_is_prime(nb) == 1)
            return (nb);
        nb++;
    }
}

/*
** EPITECH PROJECT, 2018
** my_is_prime
** File description:
** my is prim
*/

int my_is_prime(int nb)
{
    int prime = 2;

    if (nb < 2)
        return (0);
    while (prime != nb) {
        if ((nb % prime) == 0)
            return (0);
        prime++;
    }
    return (1);
}

/*
** EPITECH PROJECT, 2018
** my_compute_factorial_it
** File description:
** Returns the factorial of the number
*/

int my_compute_factorial_it(int nb)
{
    int tmp = 1;

    if (nb < 0 || nb > 12)
        return (0);
    if (nb == 1)
        return (1);
    for (; nb > 1; nb--)
        tmp *= nb;
    return (tmp);
}
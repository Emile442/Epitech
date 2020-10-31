/*
** EPITECH PROJECT, 2018
** my_compute_factorial_rec
** File description:
** Recursive of my_compute_factorial_it
*/

int my_compute_factorial_rec(int nb)
{
    int tmp = 1;

    if (nb < 0 || nb > 12)
        return (0);
    if (nb == 0)
        return (1);
    if (nb == 1)
        return (1);
    tmp = nb * my_compute_factorial_rec(nb - 1);
    return (tmp);
}
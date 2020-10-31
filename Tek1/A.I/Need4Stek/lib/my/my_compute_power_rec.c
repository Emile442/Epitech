/*
** EPITECH PROJECT, 2018
** my compute power rec
** File description:
** my compute power rec
*/

int my_compute_power_rec(int nb, int p)
{
    if (p > 0)
        return (nb * my_compute_power_rec(nb, (p - 1)));
    else
        return (1);
}

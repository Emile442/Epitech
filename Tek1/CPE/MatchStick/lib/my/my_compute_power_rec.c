/*
** EPITECH PROJECT, 2018
** my_compute_power_rec
** File description:
** Recursive of my_compute_power_it
*/

int my_compute_power_rec(int nb, int p)
{
    int tmp;

    if (p == 0)
        return (1);
    if (p < 0)
        return 0;
    tmp = nb * my_compute_power_rec(nb, p-1);
    return (tmp);
}
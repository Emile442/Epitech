/*
** EPITECH PROJECT, 2018
** my compute square root
** File description:
** find square root
*/

int my_compute_square_root(int nb)
{
    int s_r = 1;

    while (1) {
        if ((s_r * s_r) == nb)
            return (s_r);
        if ((s_r * s_r) > nb)
            return (0);
        s_r++;
    }
}

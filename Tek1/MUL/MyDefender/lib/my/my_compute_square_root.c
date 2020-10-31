/*
** EPITECH PROJECT, 2018
** my_compute_square_root
** File description:
** Returns the square root
*/

int my_compute_square_root(int nb)
{
    int result = 0;

    if (nb < 0)
        return (0);
    for (; (result * result) < nb; result++)
        if ((result * result) == nb)
            return (0);
    return (result);
}

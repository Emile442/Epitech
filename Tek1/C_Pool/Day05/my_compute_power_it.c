/*
** EPITECH PROJECT, 2018
** my_compute_power_it
** File description:
** Return the 1st argument raised to the power p where p is the second argument
*/

int my_compute_power_it(int nb, int p)
{
    int result = 1;

    for (; p >= 1; p--)
        result *= nb;
    return (result);
}
/*
** EPITECH PROJECT, 2018
** my_put_unsigned_nbr
** File description:
** Put unsigned number
*/

void my_putchar(char c);

int my_put_unsigned_nbr(unsigned int nbr)
{
    if (nbr >= 10) {
        my_put_unsigned_nbr(nbr / 10);
        my_putchar((nbr % 10) + 48);
    } else
        my_putchar(nbr + 48);
    return (0);
}
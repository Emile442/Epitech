/*
** EPITECH PROJECT, 2018
** my_put_nbr_base
** File description:
** Put nbr with base
*/
int my_strlen(char const *str);
void my_putchar(char c);

int my_put_unsigned_nbr_base(unsigned int nbr, char *base)
{
    int len = my_strlen(base);

    if (nbr)
        my_put_unsigned_nbr_base(nbr / len, base);
    else
        return (0);
    my_putchar(base[nbr % len]);
    return (0);
}
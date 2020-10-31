/*
** EPITECH PROJECT, 2018
** my_put_addr
** File description:
** get adresse
*/

int my_putstr(char const *str);
int my_put_unsigned_nbr_base(unsigned int nbr, char *base);

void my_put_addr(int str)
{
    my_putstr("0x");
    my_put_unsigned_nbr_base(str, "0123456789abcdef");
}
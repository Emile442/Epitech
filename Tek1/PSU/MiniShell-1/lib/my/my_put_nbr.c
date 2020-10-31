/*
** EPITECH PROJECT, 2018
** my_put_nbr
** File description:
** Display all the possibles values of int
*/

void my_putchar(char c);
int my_putstr(char const *str);

int my_put_nbr(int number)
{
    if (number < 0 && (number != -2147483648 || number != 2147483647)) {
        my_putchar(45);
        number = -number;
    }

    if (number < -2147483647) {
        my_putstr("2147483648");
    } else if (number >= 10) {
        my_put_nbr((number / 10));
        my_putchar((number % 10) + 48);
    } else {
        my_putchar(number + 48);
    }
    return (0);
}
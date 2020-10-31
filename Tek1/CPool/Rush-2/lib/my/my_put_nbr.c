/*
** EPITECH PROJECT, 2018
** my_put_nbr
** File description:
** Display all the possibles values of int
*/

void my_putchar(char c);

void extreme(void)
{
    my_putchar(2 + 48);
    my_putchar(1 + 48);
    my_putchar(4 + 48);
    my_putchar(7 + 48);
    my_putchar(4 + 48);
    my_putchar(8 + 48);
    my_putchar(3 + 48);
    my_putchar(6 + 48);
    my_putchar(4 + 48);
    my_putchar(8 + 48);
}

int my_put_nbr(int number)
{
    if (number < 0 && (number != -2147483648 || number != 2147483647)) {
        my_putchar(45);
        number = -number;
    }

    if (number < -2147483647) {
        extreme();
    } else if (number >= 10) {
        my_put_nbr((number / 10));
        my_putchar((number % 10) + 48);
    } else {
        my_putchar(number + 48);
    }
}
/*
** EPITECH PROJECT, 2018
** my_isneg
** File description:
** Display was the number in params is positive or negative
*/

void my_putchar(char c);

int my_isneg(int number)
{
    if (number < 0) {
        my_putchar('N');
    }
    my_putchar('P');
    return (0);
}
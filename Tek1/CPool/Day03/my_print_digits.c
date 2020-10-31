/*
** EPITECH PROJECT, 2018
** my_print_digits
** File description:
** Display all the digits in ASC order
*/

void my_putchar(char c);

int my_print_digits(void)
{
    int i = 48;

    while (i != 58) {
        my_putchar(i);
        i++;
    }
    return (0);
}
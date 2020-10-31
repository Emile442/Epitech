/*
** EPITECH PROJECT, 2018
** my_print_revalpha
** File description:
** Display the  lowercase alphabet in DESC order
*/

void my_putchar(char c);

int my_print_revalpha(void)
{
    int i = 122;

    while (i != 96) {
        my_putchar(i);
        i--;
    }
    return (0);
}
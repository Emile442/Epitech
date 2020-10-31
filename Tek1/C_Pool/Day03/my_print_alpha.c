/*
** EPITECH PROJECT, 2018
** my_print_alpha
** File description:
** Displays the lowercase alphabet in ASC order
*/

void my_putchar(char c);

int my_print_alpha(void)
{
    int i = 97;

    while (i != 123) {
        my_putchar(i);
        i++;
    }
    return (0);
}
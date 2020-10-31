/*
** EPITECH PROJECT, 2018
** my_print_comb2
** File description:
** Display all the digits in ASC order xxxx
*/

void my_putchar(char c);

int display_comb2(int a, int b)
{
    my_putchar((a / 10) + 48);
    my_putchar((a % 10) + 48);
    my_putchar(' ');
    my_putchar((b / 10) + 48);
    my_putchar((b % 10) + 48);
    if (a != 98 || b != 99) {
        my_putchar(',');
        my_putchar(' ');
        return (0);
    }
}

int my_print_comb2(void)
{
    int a = 0;
    int b = 1;

    if (a < -2147483647 || b > 2147483647) {
        return (0);
    }

    while (a <= 99) {
        b = a + 1;
        while (b < 100) {
            display_comb2(a, b);
            b++;
        }
        a++;
    }
    return (0);
}
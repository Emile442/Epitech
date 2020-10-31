/*
** EPITECH PROJECT, 2018
** my_print_comb
** File description:
** Dispay in ASC order all the numers composed by three different digits
*/

void my_putchar(char c);

int display_comb(int a, int b, int c)
{
    my_putchar(a + 48);
    my_putchar(b + 48);
    my_putchar(c + 48);
    if (a + b + c != 24) {
        my_putchar(',');
        my_putchar(' ');
    }
    return (0);
}

int third_while(int a, int b, int c)
{
    while (c <= 9) {
        display_comb(a, b, c);
        c++;
    }
    return c;
}

int my_print_comb(void)
{
    int a = 0;
    int b = 0;
    int c = 0;

    while (a <= 7) {
        b = a + 1;
        while (b <= 8) {
            c = b + 1;
            c = third_while(a, b, c);
            b++;
        }
        b = 0;
        c = 0;
        a++;
    }
    return (0);
}
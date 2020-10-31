/*
** EPITECH PROJECT, 2018
** rush2
** File description:
** Rush 2 Detect Lang
*/

#include "my.h"
#include "rush.h"

int count_alpha(const char *str);

int count_letter(const char *str, char c)
{
    int counter = 0;
    char *tmp = str;

    tmp = my_strlowcase(tmp);
    if (c >= 65 && c <= 90)
        c = c + 32;
    for (int i = 0; str[i]; i++) {
        if (tmp[i] == c)
            counter++;
    }
    return (counter);
}

void display(const char c, int nbr, int length__total)
{
    float frequency = 0;
    int uni = 0;
    int dec = 0;
    float nbr_f = nbr;

    frequency = nbr_f / length__total * 100;
    uni = frequency / 1;
    dec = frequency * 100;
    my_putchar(c);
    my_putchar(':');
    my_put_nbr(nbr);
    my_putchar(' ');
    my_putchar('(');
    my_put_nbr(uni);
    my_putchar('.');
    my_put_nbr(dec % 100);
    if (!(dec % 100))
        my_putchar(48);
    my_putchar('%');
    my_putchar(')');
    my_putchar('\n');
}

char *lang(float en, float fr, float ge, float es)
{
    if (fr > en && fr > ge && fr > es)
        return ("=> French");
    if (en > fr && en > ge && en > es)
        return ("=> English");
    if (ge > en && ge > fr && ge > es)
        return ("=> German");
    if (es > en && es > fr && es > ge)
        return ("=> Spanish");
    return ("=> Unknow");
}

void result(const char *str, int length_total)
{
    float collect[27];
    float en = 0;
    float fr = 0;
    float ge = 0;
    float es = 0;
    char letter = 97;
    char *tmp = str;

    for (int i = 0; i < 26; i++) {
        collect[i] = count_letter(my_strlowcase(tmp), letter);
        letter++;
    }
    for (int i = 0; i < 26; i++) {
        en += collect[i] * STATS[i][0];
        fr += collect[i] * STATS[i][1];
        ge += collect[i] * STATS[i][2];
        es += collect[i] * STATS[i][3];
    }
    my_putstr(lang(en, fr, ge, es));
}

int main(int argc, char const **argv)
{
    int length = 0;
    int counter = 0;

    if (argc == 1)
        return (84);
    length = count_alpha(argv[1]);
    for (int i = 2; i < argc; i++) {
        int tmp;
        tmp = count_letter(argv[1], argv[i][0]);
        counter += tmp;
        display(argv[i][0], tmp, length);
    }
    result(argv[1], length);
    return (0);
}

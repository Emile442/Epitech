/*
** EPITECH PROJECT, 2018
** count_alpha
** File description:
** count Alpha
*/


int count_alpha(const char *st)
{
    int counter = 0;

    for (int i = 0; st[i]; i++) {
        if ((st[i] >= 'A' && st[i] <= 'Z') || (st[i] >= 'a' && st[i] <= 'z'))
            counter++;
    }
    return (counter);
}
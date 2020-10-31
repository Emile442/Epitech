/*
** EPITECH PROJECT, 2018
** infinit_add
** File description:
** Inifinit add
*/

#include <stdlib.h>
#include "my.h"

char to_c(int i);
int to_i(char c);
int size(char const *a, char const *b);

int eq_calc_sous(char num1, char num2, int rest)
{
    int nbr1 = to_i(num1);
    int nbr2 = to_i(num2);
}

void sous(char *result, char *num1, char *num2, int rest)
{
    int max_size = size(num1, num2);
    int tmp = 0;
    int nbr1;
    int nbr2;

    for (int i = 0; i < max_size; i++) {
        nbr1 = to_i(num1[i]);
        nbr2 = to_i(num2[i]);

        if (nbr1 < (nbr2 + rest)) {
            tmp = (nbr1 + 10) - (nbr2 + rest);
            rest = (nbr1 + 10) / 10;
        } else {
            tmp = nbr1 - (nbr2 + rest);
            rest = 0;
        }

        i = my_strlen(result);
        result[i] = to_c(tmp % 10);
        result[i + 1] = '\0';
    }
}

char *soustraction(char *nb1, char *nb2)
{
    int max_size = size(nb1, nb2);
    char *result = malloc(sizeof(char) * (max_size) + 1);
    char *num1 = malloc(sizeof(char) * (max_size) + 1);
    char *num2 = malloc(sizeof(char) * (max_size) + 1);
    int rest = 0;
    int i = 0;

    my_strncpy(num1, my_revstr(nb1), my_strlen(nb1));
    my_strncpy(num2, my_revstr(nb2), my_strlen(nb2));
    sous(result, num1, num2, rest);
    return (my_revstr(result));
}
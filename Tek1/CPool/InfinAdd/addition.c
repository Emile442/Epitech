/*
** EPITECH PROJECT, 2018
** addition
** File description:
** Addiction
*/

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
int mode(char const *a, char const *b);

int eq_calc(char num1, char num2, int rest)
{
    int nbr1 = to_i(num1);
    int nbr2 = to_i(num2);

    if (num1 && !num2)
        return (nbr1 + rest);
    else if (!num1 && num2)
        return (nbr2 + rest);
    else
        return ((nbr1 + nbr2) + rest);
}

void add(char *result, char *num1, char *num2, int rest)
{
    int max_size = size(num1, num2);
    int tmp = 0;

    for (int i = 0; i < max_size; i++) {
        tmp = eq_calc(num1[i], num2[i], rest);
        i = my_strlen(result);
        result[i] = to_c(tmp % 10);
        result[i + 1] = '\0';
        rest = (tmp >= 10) ? (tmp / 10) : 0;
    }
}

char *addition(char *nb1, char *nb2)
{
    int max_size = size(nb1, nb2);
    int type = mode(nb1, nb2);
    char *result = malloc(sizeof(char) * (max_size) + 1);
    char *num1 = malloc(sizeof(char) * (max_size) + 1);
    char *num2 = malloc(sizeof(char) * (max_size) + 1);
    int rest = 0;
    int i = 0;

    my_strncpy(num1, my_revstr(nb1), my_strlen(nb1));
    my_strncpy(num2, my_revstr(nb2), my_strlen(nb2));
    add(result, num1, num2, rest);
    if (rest) {
        i = my_strlen(result);
        result[i] = to_c(rest);
        result[i + 1] = '\0';
    }
    return (my_revstr(result));
}
/*
** EPITECH PROJECT, 2018
** infinit_add
** File description:
** Inifinit add
*/

#include <stdlib.h>
#include "my.h"

char *addition(char *nb1, char *nb2);
char *soustraction(char *nb1, char *nb2);
int size(char const *a, char const *b);
char *c_to_p(const char *c);
int mode(char const *a, char const *b);
char *add_sign(const char *c);

char *infinit_add(char *nb1, char *nb2)
{
    int max_size = size(nb1, nb2);
    int type = mode(nb1, nb2);
    char *result = malloc(sizeof(char) * (max_size) + 1);
    char *tmp = malloc(sizeof(char) * (max_size) + 1);

    if (type == 3)
        return (add_sign(addition(c_to_p(nb1), c_to_p(nb2))));
    if (type == 0)
        return (addition(nb1, nb2));
    else
        return (soustraction(nb1, nb2));
}
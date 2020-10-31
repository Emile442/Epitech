/*
** EPITECH PROJECT, 2020
** parser_look.c
** File description:
** parser_look
*/

#include "zappy_ai.h"

int count_tiles(char *str)
{
    int nb_tiles = 0;

    for (int i = 0; str[i] != '\0'; i++)
        if (str[i] == ',')
            nb_tiles += 1;
    nb_tiles += 1;
    return (nb_tiles);
}

char **alloc_tab(char *str)
{
    char **tab = malloc(sizeof(char *) * strlen(str));

    for (int i = 0; i < count_tiles(str); i++)
        tab[i] = malloc(sizeof(char) * strlen(str));
    return (tab);
}

void parsertwo(char **tab, char *str, int i, int a)
{
    while (str[i] == ',') {
        strcpy(tab[a], "NONE\0");
        i++;
        a++;
    }
}

char **parser_look(char *str)
{
    char **tab = alloc_tab(str);
    for (int i = 0, n = 0, a = 0; str[i] != '\0'; i++, n++) {
        if (str[i] == '[')
            i++;
        if (str[i] == ',') {
            tab[a][n + 1] = '\0';
            a++, i++;
            n = 0;

            i++;
        }
        if (str[i] == ']')
            tab[a][n] = '\0';
        else
            tab[a][n] = str[i];
    }
    return (tab);
}
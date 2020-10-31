/*
 ** EPITECH PROJECT, 2018
 ** main
 ** File description:
 ** Main File
 */

 #include <stddef.h>
 #include <stdlib.h>
 #include <unistd.h>
 #include <stdbool.h>

 #include "my.h"
 #include "stumper.h"

char found_the_smaller(char c, char* str)
{
    char *tmp = str;
    int val = c;
    int key = NULL;

    for (int i = 0; tmp[i]; i++)
        if (tmp[i] != 32 && tmp[i] != '\2' && tmp[i] < val) {
             val = tmp[i];
             key = i;
        }
    str[key] = '\2';
    my_printf("\nDEBUG: %s\n", str);
    return (val);
 }

void sort_word(char* words)
{
    char* copy = words;
    bool is_word = false;
    bool bigger = true;
    char tmp;

    my_printf("DEBUG: %s\n", words);
    for (int i = 0; i < my_strlen(copy); i++) {
        if (copy[i] == 32) {
            my_putchar(32);
            copy[i] = '\2';
        } else if (copy[i] != '\2') {
            tmp = found_the_smaller(copy[i], copy);
            my_putchar(tmp);
        }
    }


    my_printf("\nFINAL: %s\n", copy);
    for (int j = 0; copy[j] != '\0'; j++)
        if (copy[j] != '\2')
            sort_word(copy);
}

int main(int ac, char** av)
{
    if (ac == 1)
        my_printf("\n");
    else if (ac == 2) {
        sort_word(av[1]);
    }
    else
        return (84);
    return (0);
}

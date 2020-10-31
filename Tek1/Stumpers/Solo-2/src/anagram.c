/*
** EPITECH PROJECT, 2019
** CPE_solostumper_2_2018
** File description:
** anagram
*/

#include <stdio.h>
#include <stdbool.h>
#include <unistd.h>

#include "my.h"
#include "stumper.h"

int found_c_in_str(char* str, char c)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == c || (str[i] - 32) == c || (str[i] + 32) == c) {
            return (i);
        }
    }
    return (-1);
}

void anagram(char* auth_char_p, char* str_p)
{
    bool anagram = true;
    char* auth_char = auth_char_p;
    char* str = str_p;
    int tmp = -2;

    for (int i = 0; str[i] != '\0'; i++) {
        tmp = found_c_in_str(auth_char, str[i]);
        if (tmp == -1) {
            anagram = false;
            break;
        } else {
            auth_char[tmp] = '\1';
        }
    }
    my_printf("%s\n", anagram ? "anagram!" : "no anagrams.");
}

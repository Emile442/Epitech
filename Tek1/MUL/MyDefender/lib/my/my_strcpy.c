/*
** EPITECH PROJECT, 2018
** my_strcpy
** File description:
** Copies string in a other string
*/

char *my_strcpy(char *dest, char const *src)
{
    for (int i = 0; src[i] != '\0';) {
        dest[i] = src[i];
        i++;
        dest[i] = 0;
    }
    return (dest);
}
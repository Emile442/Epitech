/*
** EPITECH PROJECT, 2018
** my_strncat
** File description:
** concatenates n characters of the src string to the end of the dest string
*/

char *my_strncat(char *dest, char const *src, int nb)
{
    int len = 0;

    for (; dest[len] != 0; len++);
    for (int i = 0; src[i] != 0 && i < nb; i++) {
        dest[len] = src[i];
        len++;
    }
    dest[len] = 0;
    return dest;
}
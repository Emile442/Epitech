/*
** EPITECH PROJECT, 2018
** my_strncpy
** File description:
** Copies n characters from a string into another
*/

char *my_strncpy(char *dest, char *src, int n)
{
    for (int i = 0; n > 0;) {
        if (src[i] != '\0')
            dest[i] = src[i];
        i++;
        dest[i] = 0;
        n--;
    }
    return (dest);
}

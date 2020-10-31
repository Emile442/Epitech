/*
** EPITECH PROJECT, 2018
** my_strncpy
** File description:
** Copies n characters from a string into another
*/

char *my_strncpy(char *dest, char *src, int n)
{
    int i = 0;
    
    for (; n > i && src[i] != 0; i++)
        dest[i] = src[i];
    dest[i] = 0;
    return (dest);
}
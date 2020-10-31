/*
** EPITECH PROJECT, 2018
** my_strlowcase
** File description:
** Convert string to lowercase
*/

char *my_strlowcase(char *str)
{
    for (int i = 0; str[i] != '\0'; i++)
        str[i] = (str[i] >= 65 && str[i] <= 90) ? str[i] + 32 : str[i];
    return (str);
}
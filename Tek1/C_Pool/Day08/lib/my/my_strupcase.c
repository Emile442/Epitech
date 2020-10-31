/*
** EPITECH PROJECT, 2018
** my_strupcase
** File description:
** To uppercase
*/

char *my_strupcase(char *str)
{
    for (int i = 0; str[i] != '\0'; i++)
        str[i] = (str[i] >= 97 && str[i] <= 122) ? str[i] - 32 : str[i];
    return (str);
}
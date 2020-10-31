/*
** EPITECH PROJECT, 2018
** my_strcmp
** File description:
** strcpm function
*/

int my_strlen(char const *str);

int	my_strcmp(char *s1, char *s2)
{
    for (int i = 0; s1 != 0; i++) {
        if (s1[i] > s2[i])
            return (1);
        else if (s1[i] < s2[i])
            return (-1);
        if (s1[i] == '\0')
            return (0);
    }
    return (0);
}
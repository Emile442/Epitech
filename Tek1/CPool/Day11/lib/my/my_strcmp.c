/*
** EPITECH PROJECT, 2018
** my_strcmp
** File description:
** strcpm function
*/

// premier inf au deuxieme -1
// premier agal == 0
// Super au dexiemet 1

int my_strlen(char const *str);

int	my_strcmp(char *s1, char *s2)
{
    if (!s1)
        return (0);
    if (my_strlen(s1) != my_strlen(s2))
        return (1);
    for (int i = 0; s1[i] != 0; i++) {
        if (!s1)
            return (1);
        if (!s2)
            return (1);
        if (s1[i] != s2[i])
            return (1);
    }
    return (0);
}
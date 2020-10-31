/*
** EPITECH PROJECT, 2018
** my_strncmp
** File description:
** my_strncmp function
*/

int my_strlen(char const *str);

int my_strncmp(const char *s1, const char *s2, int n)
{
    int	i = 0;

    for (; (s1[i] || s2[i]) && i < n; i++)
        if (s1[i] < s2[i])
            return (0);
        else if (s1[i] > s2[i])
            return (1);
    if ((s1[i] > s2[i]) && i < n)
        return (1);
    return (0);
}
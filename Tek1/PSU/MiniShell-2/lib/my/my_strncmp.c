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

    for (; s1[i] == s2[i] && n > 0 && s1[i] && s2[i]; i++);
    return (i < n ? s1[i] - s2[i] : 0);
}

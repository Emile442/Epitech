/*
** EPITECH PROJECT, 2019
** count words
** File description:
** counts words (comments excluded)
*/

int count_words(char *str)
{
    int words = 0;
    int i = 0;

    while (str[i]) {
        while (str[i] == ' ' || str[i] == '\t')
            i++;
        if (str[i] == '#')
            break;
        if (str[i])
            words++;
        while (str[i] && str[i] != ' ' && str[i] != '\t')
            i++;
    }
    return (words);
}

/*
** EPITECH PROJECT, 2019
** My str to word array
** File description:
** take char * to a char **
*/

#include "sh.h"

char **line_formating_malloc_each_word(char *str, char **word_array, int count)
{
    int *count_char = malloc(sizeof(int) * count);
    bool quote = false;

    if (!count_char)
        return (NULL);
    for (int i = 0; i < count; count_char[i] = 0, i++);
    for (int i = 0, j = 0; str[i] && j < count; i++) {
        (str[i] == '"' || str[i] == 39) ? quote = !quote : 0;
        if ((str[i] == ' ' || str[i] == '\t') && str[i - 1] != '\\' &&
            (i && str[i - 1] != ' ' && str[i - 1] != '\t') && quote == false)
            j++;
        else if (str[i] != ' ' && str[i] != '\t' && quote == true
            && str[i - 1] == '\\')
            count_char[j]++;
    }
    for (int i = 0; i < count; word_array[i][count_char[i]] = 0, i++) {
        if (!(word_array[i] = malloc(sizeof(char) * (count_char[i] + 1))))
            return (NULL);
    }
    return (word_array);
}

char **line_formating_malloc_word(char *str)
{
    char **word_array;
    int i = 0;
    int count = 1;
    bool quote = false;

    for (;str[i]; (str[i] == '"' || str[i] == 39) ? quote = !quote : 0, i++) {
        if ((str[i] == ' ' || str[i] == '\t')
            && (i && str[i - 1] != ' ' && str[i - 1] != '\t') && quote == false
            && str[i - 1] != '\\')
            count++;
    }
    ((str[i - 1] == ' ' || str[i - 1] == '\t') && quote == false
    && str[i - 1] != '\\') ? count-- : 0;
    if (!count)
        return (NULL);
    if (!(word_array = malloc(sizeof(char *) * (count + 1))))
        return (NULL);
    word_array[count] = NULL;
    word_array = line_formating_malloc_each_word(str, word_array, count);
    return (word_array);
}

char *clean_line_back_slash(char *str)
{
    char *temp1;
    bool back_slash = false;
    int b = 0;

    for (int i = 0; str[i]; i++) {
        if (str[i] == '\\') {
            str[i] = ' ';
            back_slash = true;
        }
    }
    if (back_slash == true) {
        for (; str[b] != ' '; b++);
        if (!(temp1 = malloc(sizeof(char) * (b + 1))))
            return (NULL);
        for (int c = 0; c != b; temp1[c] = str[c], c++);
        str = str + b + 1;
        str = strcat(temp1, str);
    }
    return (str);
}

char **clean_line(char **array)
{
    char *temp = '\0';

    for (int i = 0; array[i]; i++) {
        if (array[i][0] == '"' || array[i][0] == 39)
            temp = malloc(sizeof(char) * (strlen(array[i]) - 1));
        if ((array[i][0] == '"' || array[i][0] == 39) && !temp)
            return (NULL);
        if ((array[i][0] == '"' || array[i][0] == 39) && temp) {
            strncpy(temp, array[i], strlen(array[i]) - 1);
            strcpy(array[i], temp);
            array[i]++;
        }
    }
    for (int c = 0; array[c]; c++)
        array[c] = clean_line_back_slash(array[c]);
    free(temp);
    return (array);
}

char **line_formating(char *str)
{
    char **word_array;
    bool quote = false;

    word_array = line_formating_malloc_word(str);
    if (!word_array)
        return (NULL);
    for (int i = 0, j = 0, k = 0; str[i]; i++) {
        (str[i] == '"' || str[i] == 39) ? quote = !quote : 0;
        if ((str[i] == ' ' || str[i] == '\t') && str[i - 1] != '\\'
        && (str[i - 1] != ' ' && str[i -1] != '\t') && i && quote == false) {
            k = 0;
            j++;
        }
        else if ((str[i] != ' ' && str[i] != '\t') || quote == true
        || str[i - 1] == '\\') {
            word_array[j][k] = str[i];
            k++;
        }
    }
    return (clean_line(word_array));
}

/*
** EPITECH PROJECT, 2018
** lib_my_strlen
** File description:
** my strlen for libraries
*/

int my_strlen(char const *str)
{
    int count = 0;

    while (str[count] != '\0') {
        count++;
    }
    return (count);
}

int my_strarray_len(char * const *array)
{
    int count = 0;

    while (array[count])
        count++;
    return (count);
}

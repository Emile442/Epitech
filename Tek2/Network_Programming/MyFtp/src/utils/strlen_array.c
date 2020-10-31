/*
** EPITECH PROJECT, 2020
** MyFtp
** File description:
** strlen_array
*/

int strlen_array(char** array)
{
    int rt = 0;
    for (int i = 0; array[i]; i++)
        rt++;
    return (rt);
}

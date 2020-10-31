/*
** EPITECH PROJECT, 2019
** 42sh
** File description:
** Utils
*/

#include <sh.h>

char **get_path(char **env)
{
    char **path;
    char *buffer;
    int count = 0;

    for (;env[count] && !my_strncmp(env[count], "PATH=", 5); count++);
    if (!env[count])
        return (NULL);
    buffer = my_strcpy(env[count] + 5);
    for (int i = 0; buffer[i]; i++)
        (buffer[i] == ':') ? buffer[i] = ' ' : 0;
    path = my_str_to_word_array(buffer);
    return (path);
}

/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2018
** File description:
** filehandle
*/


#include "my_shell.h"

char* get_file_path(char* path, char* filename)
{
    int len = 0;
    char *str;

    if (my_strcmp(filename, "") == 0 || filename == NULL)
        return ("");
    len = my_strlen(path) + my_strlen(filename) + 2;
    str = malloc(sizeof(char) * len);
    if (filename[0] == '/')
        return (filename);
    my_memset(str, '\0', len);
    my_strcpy(str, path);
    if (path[my_strlen(path)] != '/')
        my_strcat(str, "/");
    my_strcat(str, filename);
    return (str);
}

bool file_exist(char* filepath)
{
    return (open(filepath, O_RDONLY) == -1 ? false : true);
}

bool is_directory(char* path)
{
    DIR* directory = opendir(path);

    if (directory != NULL) {
        closedir(directory);
        return (true);
    }
    return (false);
}

char* get_current_dir(char* pwd)
{
    int f_len = my_strlen(pwd);
    int dir_len = 0;
    char* tmp = my_strdup(pwd);

    for (int i = 0; pwd[i]; i++)
        if (pwd[i] == '/')
            dir_len = 0;
        else
            dir_len++;
    for (int i = 0; i < (f_len - dir_len); i++)
        tmp++;
    return (tmp);
}

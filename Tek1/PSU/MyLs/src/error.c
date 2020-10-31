/*
** EPITECH PROJECT, 2019
** PSU_my_ls_2018
** File description:
** Error
*/

#include "my.h"
#include "my_ls.h"

void error_file_unknow(char* path)
{
    my_puterror("ls: cannot access '");
    my_puterror(path);
    my_puterror("': No such file or directory\n");
    exit(EPI_FAILURE);
}

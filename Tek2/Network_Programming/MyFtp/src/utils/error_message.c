/*
** EPITECH PROJECT, 2020
** MyFtp
** File description:
** utils
*/

#include "ftp.h"

void exit_with_error(char* msg)
{
    perror(msg);
    exit(84);
}

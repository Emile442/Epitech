/*
** EPITECH PROJECT, 2018
** fs_file
** File description:
** File Function
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include "my.h"

int fs_open_file(char const *filepath)
{
    int file = open(filepath, O_RDONLY);

    if (file == -1)
        exit(84);
    return (file);
}

void fs_read_file(int fd, char *buffer, int size)
{
    int len = read(fd, buffer, size);

    if (len == -1)
        exit(EPI_FAILURE);
    else if (len == 0)
        my_putstr("read has nothing more to read\n");
    if (len == -1 || len == 0)
        exit(EPI_FAILURE);
    close(fd);
}
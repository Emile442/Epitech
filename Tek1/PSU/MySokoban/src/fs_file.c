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

#include "sokoban.h"

int fs_open_file(char const *filepath)
{
    int file = open(filepath, O_RDONLY);

    if (file == -1)
        exit_map();
    return (file);
}

void fs_read_file(int fd, char *buffer, int size)
{
    int len = read(fd, buffer, size);

    if (len == -1 || len == 0)
        exit_map();
    close(fd);
}

int get_filesize(char* const file)
{
    struct stat sb;

    if (stat(file, &sb) == -1)
        exit_map();
    return (sb.st_size);
}
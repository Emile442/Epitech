/*
** EPITECH PROJECT, 2018
** cat
** File description:
** Cat
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include "my.h"

void empty_args(void)
{
    int len = 0;
    char buff[30000];

    while (1) {
        len = read(0, buff, sizeof(buff));
        for (int j = 0; j < len; j++)
            my_putchar(buff[j]);
    }
}

int cat(int argc, char const **argv)
{
    int file = 0;
    int len = 0;
    char buff[30000];

    if (argc < 2)
        empty_args();
    for (int i = 1; i < argc; i++) {
        file = open(argv[i], O_RDONLY);
        if (file == -1) {
            my_put_nbr(errno);
            return (84);
        }
        len = read(file, buff, sizeof(buff));
        write(1, buff, len);
        close(file);
    }
    return (0);
}
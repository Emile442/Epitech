/*
** EPITECH PROJECT, 2020
** MyProject
** File description:
** desc
*/

#include "ftp.h"
#include <sys/types.h>
#include <sys/stat.h>

void ftp(int port, const char* path)
{
    server_t* server = server_init(port, path);

    printf("[FTP SERVER] Launch on port %d in %s\n", port, path);
    while (!server->exit) {
        server_wait_connection(server);
    }
    close(server->fd);
    free(server);
}

int main(int argc, const char **argv)
{
    struct stat s;

    if (argc != 3)
        return (84);
    if (stat(argv[2], &s) == -1)
        return (84);
    ftp(atoi(argv[1]), argv[2]);
    return (0);
}

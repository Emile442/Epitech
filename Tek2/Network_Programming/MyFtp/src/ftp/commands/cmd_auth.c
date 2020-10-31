/*
** EPITECH PROJECT, 2020
** MyFtp
** File description:
** auth
*/

#include "ftp.h"

const accounts_tab_t accounts_tab[] = {
    {"Anonymous", "", NULL},
    {"Emile", "epi", "src"},
    {NULL, NULL, NULL}
};

void cmd_auth_username(client_t* client, char** cmd)
{
    if (strlen_array(cmd) != 2) {
        ftp_response(client, "Login incorrect.", "530");
        return;
    }
    client->username = strdup(cmd[1]);
    ftp_response(client, "User name okay, need password.", "331");
}

void password_verif(client_t* client)
{
    if (client->auth)
        ftp_response(client, "User logged in, proceed.", "230");
    else {
        ftp_response(client, "Login incorrect.", "530");
        if (client->username)
            free(client->username);
        client->username = NULL;
    }
}

void cmd_auth_password(client_t* client, char** cmd)
{
    if (strlen_array(cmd) > 2) {
        ftp_response(client, "Login incorrect.", "530");
        return;
    }
    if (client->username == NULL) {
        ftp_response(client, "Please login with USER and PASS.", "530");
        return;
    }
    for (int i = 0; accounts_tab[i].username; i++) {
        if (strcmp(accounts_tab[i].username, client->username) == 0 && \
        strcmp(accounts_tab[i].password, cmd[1] ? cmd[1] : "") == 0) {
            client->auth = true;
            client->path = accounts_tab[i].home ? \
        realpath(accounts_tab[i].home, NULL) : client->path;
            chdir(client->path);
        }
    }
    password_verif(client);
}

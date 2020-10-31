/*
** EPITECH PROJECT, 2019
** 42sh
** File description:
** Redirection utils
*/

#include <sh.h>

char *redirect_str[5] =
{
    "<<",
    ">>",
    ">",
    "<",
    NULL
};

int check_redirect_str(char *prompt, int count)
{
    for (int i = 0; redirect_str[i]; i++) {
        if (my_strncmp(redirect_str[i], &prompt[count],
            my_strlen(redirect_str[i])))
            return (my_strlen(redirect_str[i]));
    }
    return (0);
}

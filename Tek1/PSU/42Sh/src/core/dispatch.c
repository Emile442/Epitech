/*
** EPITECH PROJECT, 2019
** 42sh
** File description:
** core/dispatch
*/

#include "sh.h"

const fct_tab_t fct_tab[MAX_FCT] = {
    {"cd", make_chdir},
    {"env", make_env},
    {"setenv", make_setenv},
    {"unsetenv", make_unsetenv},
    {"exit", make_exit},
    {"echo", make_echo},
    {"which", make_which},
    {"alias", make_alias},
    {"unalias", make_unalias},
    {"repeat", make_repeat}
};

bool is_builtins(char* cmd)
{
    for (int i = 0; i < MAX_FCT; i++)
        if (my_strcmp(cmd, fct_tab[i].str))
            return (true);
    return (false);
}

int make_basic_cmd(shell_t* shell)
{
    int state = 1;

    for (int i = 0; i < MAX_FCT; i++) {
        if (my_strcmp(shell->command[0], fct_tab[i].str)) {
            shell->env = fct_tab[i].fct(shell);
            state = 0;
        }
    }
    return (state);
}

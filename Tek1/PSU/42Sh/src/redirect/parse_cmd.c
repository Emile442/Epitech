/*
** EPITECH PROJECT, 2019
** 42sh
** File description:
** Parse cmds
*/

#include <sh.h>

const char *separator[5] =
{
    ";",
    "||",
    "&&",
    "|",
    NULL
};

int check_separator_str(char *prompt)
{
    for (int i = 0; separator[i]; i++) {
        if (my_strncmp(separator[i], prompt, my_strlen(separator[i])))
            return (my_strlen(separator[i]));
    }
    return (0);
}

int cmds_and_separator_number(char *prompt)
{
    int count = 1;
    int separator_len = 0;

    for (int i = 0; prompt[i]; i++) {
        if ((count % 2) && (separator_len = check_separator_str(&prompt[i]))) {
            count++;
            i += separator_len - 1;
            separator_len = 0;
        } else if (!(count % 2) && prompt[i] != ' ' && prompt[i] != '\t') {
            count++;
        }
    }
    return (count);
}

char **copy_prompt(char **cmds, char *prompt, int **value)
{
    int separator_size = check_separator_str(&prompt[*value[1]]);

    if (*value[2] < *value[0]) {
        cmds[*value[2]] = my_strncpy(&prompt[*value[3]], *value[1] - *value[3]);
        if (!cmds[*value[2]])
            return (NULL);
    }
    if (*value[2] + 1 < *value[0]) {
        cmds[*value[2] + 1] = my_strncpy(&prompt[*value[1]], separator_size);
        if (!cmds[*value[2] + 1])
            return (NULL);
        *value[1] += separator_size;
    }
    *value[3] = *value[1];
    *value[2] += 2;
    return (cmds);
}

char **parse_prompt(char *prompt)
{
    char **result = NULL;
    int count = cmds_and_separator_number(prompt);
    int buffer = 0;

    result = malloc(sizeof(char *) * (count + 1));
    if (!result)
        return (NULL);
    result[count] = NULL;
    for (int i = 0, j = 0; !i || prompt[i - 1]; i++) {
        if (!prompt[i] || check_separator_str(&prompt[i])) {
            result = copy_prompt(result, prompt,
            (int *[4]) {&count, &i, &j, &buffer});
        }
        if (!result)
            return (NULL);
    }
    return (result);
}

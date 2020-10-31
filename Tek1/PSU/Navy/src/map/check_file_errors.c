/*
** EPITECH PROJECT, 2019
** check file errors
** File description:
** check errors in the file content
*/

#include "my.h"
#include <stdlib.h>

bool is_line_valid(char **content, int line)
{
    if (my_strlen(content[line]) != 7 ||
        content[line][0] != '0' + 2 + line ||
        content[line][1] != ':'|| content[line][4] != ':'||
        content[line][2] < 'A' || content[line][2] > 'H' ||
        content[line][5] < 'A' || content[line][5] > 'H' ||
        content[line][3] < '0' || content[line][3] > '8' ||
        content[line][6] < '0' || content[line][6] > '8' ||
        (content[line][2] == content[line][5] &&
        content[line][3] == content[line][6]) ||
        (content[line][2] != content[line][5] &&
        content[line][3] != content[line][6]))
        return (false);
    return (true);
}

bool check_file_errors(char **content)
{
    int lines = 0;

    if (!content)
        return (true);
    for (; content[lines]; lines++)
        if (!is_line_valid(content, lines)) {
            (free(content[0]), free(content));
            return (true);
        }
    if (lines != 4) {
        (free(content[0]), free(content));
        return (true);
    }
    return (false);
}

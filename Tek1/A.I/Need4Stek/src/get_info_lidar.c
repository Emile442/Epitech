/*
** EPITECH PROJECT, 2019
** n4s
** File description:
** get_info_lidar
*/

#include "n4s.h"

void get_info_lidar(s_n4s *n4s)
{
    char *info = "GET_INFO_LIDAR\n";
    int i = 0;

    write(1, info, my_strlen(info));
    n4s->buf = get_command_player();
    if (n4s->buf == NULL)
        exit(84);
    for (; n4s->buf[i] != ':' && n4s->buf[i] != '\0'; i++);
    if (n4s->buf[i + 1] == 'K' && n4s->buf[i + 2] == 'O')
        exit(84);
    n4s->get_info = my_str_to_word_array_bis(':', n4s->buf);
    for (int a = 0; a != 35; a++)
        if (n4s->get_info[a] == NULL)
            exit(84);
    for (int a = 0; n4s->get_info[a]; a++)
        dprintf(2, "\n\n%s\n\n", n4s->get_info[a]);
}

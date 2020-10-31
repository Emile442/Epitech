/*
** EPITECH PROJECT, 2019
** get map
** File description:
** gets the map from a filepath and returns null in case of an error
*/

#include "../include/navy.h"
#include <stdlib.h>

char **initialize_map(void)
{
    char **map = malloc(sizeof(char *) * 9);

    if (!map)
        return (NULL);
    for (int i = 0; i < 8; i++) {
        if (!(map[i] = malloc(sizeof(char) * 9)))
            return (NULL);
        for (int j = 0; j < 8; j++)
            map[i][j] = '.';
        map[i][8] = 0;
    }
    map[8] = NULL;
    return (map);
}

int add_ship_to_map(char const *line, char **map)
{
    int len = line[0];
    int actual_len;

    (line[2] == line[5]) ? (actual_len = line[3] - line[6]):
    (actual_len = line[2] - line[5]);
    actual_len = actual_len > 0 ? actual_len : -actual_len;
    if (actual_len + 1 != len || map[(int)line[5]][(int)line[6]] != '.')
        return (0);
    for (int x = line[2]; x != line[5]; x < line[5] ? x++:x--) {
        if (map[(int)line[3]][x] != '.')
            return (0);
        map[(int)line[3]][x] = len + '0';
    }
    for (int y = line[3]; y != line[6]; y < line[6] ? y++:y--) {
        if (map[y][(int)line[2]] != '.')
            return (0);
        map[y][(int)line[2]] = len + '0';
    }
    map[(int)line[6]][(int)line[5]] = len + '0';
    return (1);
}

char **get_map_from_file(char const *filepath)
{
    char **map;
    char **content = load_file_in_2d_array(filepath);

    if (check_file_errors(content) || !(map = initialize_map()))
        return (NULL);
    for (int i = 0; i < 4; i++) {
        content[i][0] -= '0';
        content[i][2] -= 'A';
        content[i][5] -= 'A';
        content[i][3] -= '1';
        content[i][6] -= '1';
        if (!add_ship_to_map(content[i], map))
            return (NULL);
    }
    (free(content[0]), free(content));
    return (map);
}

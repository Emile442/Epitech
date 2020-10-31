/*
** EPITECH PROJECT, 2018
** game_utils
** File description:
** Game Utils
*/

#include "my_runner.h"
#include "my.h"

sfIntRect set_scale(int top, int left, int width, int height)
{
    sfIntRect rect;

    rect.top = top;
    rect.left = left;
    rect.width = width;
    rect.height = height;
    return (rect);
}

void init_sprite(sprite_texture_t *st, char* filepath)
{
    st->texture = sfTexture_createFromFile(filepath, NULL);
    st->sprite = sfSprite_create();
    sfSprite_setTexture(st->sprite, st->texture, sfTrue);
}

void show_help(void)
{
    my_printf("Finite runner created with CSFML.\n");
    my_printf("\nUSAGE\n");
    my_printf(" ./my_runner map.txt");
    my_printf("\n");
    my_printf("\nOPTIONS\n");
    my_printf(" -h\t\tprint the usage and quit.\n");
    my_printf("\nUSER INTERACTIONS\n");
    my_printf(" SPACE_KEY\tjump.\n");
}

static int int_len(int nb)
{
    int size = 1;

    while (nb != 0) {
        nb = nb /10;
        size++;
    }
    return (size + 1);
}

char *int_to_str(int nb)
{
    int size = int_len(nb);
    char *str = malloc(sizeof(char) * size);

    my_memset(str, '\0', size);
    if (nb == 0) {
        str[0] = '0';
        str[1] = '\0';
        return (str);
    }
    for (int i = 0; nb != 0; i++) {
        str[i] = (nb % 10) + '0';
        nb = nb / 10;
    }
    return (my_revstr(str));
}

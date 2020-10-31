/*
** EPITECH PROJECT, 2018
** utils
** File description:
** Utils
*/

#include "my_defender.h"

bool is_in_range(int a, int b, int value)
{
    if (value >= a && value <= b)
        return (true);
    return (false);
}

void button_init(button_t* button, sfVector2f position, sfVector2f size, \
char* path)
{
    button->texture = sfTexture_createFromFile(path, NULL);
    button->position = position;
    button->hidden = false;
    button->txt_clicked = NULL;
    button->txt_hover = NULL;
    sfRectangleShape_setSize(button->rect, size);
    sfRectangleShape_setPosition(button->rect, position);
    sfRectangleShape_setTexture(button->rect, button->texture, sfTrue);
}

void button_destroy(button_t* button)
{
    sfTexture_destroy(button->texture);
    sfRectangleShape_destroy(button->rect);
}

bool button_is_clicked(button_t* button, sfVector2i mouse)
{
    sfVector2f rect_pos = sfRectangleShape_getPosition(button->rect);
    sfVector2f rect_size = sfRectangleShape_getSize(button->rect);
    int rgX = is_in_range(rect_pos.x, rect_pos.x + rect_size.x, mouse.x);
    int rgY = is_in_range(rect_pos.y, rect_pos.y + rect_size.y, mouse.y);

    if (rgX && rgY)
        return (true);
    return (false);
}

/*
** EPITECH PROJECT, 2020
** cpp_d01_2019
** File description:
** Ex02
*/

#include "bitmap.h"

uint16_t get_magic(void)
{
    #if BYTE_ORDER == BIG_ENDIAN
        return (0x4D42);
    #else
        return (0x424D);
    #endif
}

void make_bmp_header(bmp_header_t *header , size_t size)
{
    header->magic = get_magic();
    header->size = size * size * 4 + \
    sizeof(bmp_header_t) + sizeof(bmp_info_header_t);
    header->_app1 = 0;
    header->_app2 = 0;
    header->offset = sizeof(bmp_header_t) + sizeof(bmp_info_header_t);
}

void make_bmp_info_header(bmp_info_header_t *header, size_t size)
{
    header->size = 40;
    header->width = size;
    header->height = size;
    header->planes = 1;
    header->bpp = 32;
    header->compression = 0;
    header->raw_data_size = size * size * 4;
    header->h_resolution = 0;
    header->v_resolution = 0;
    header->palette_size = 0;
    header->important_colors = 0;
}

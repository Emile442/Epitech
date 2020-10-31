/*
** EPITECH PROJECT, 2020
** cpp_d01_2019
** File description:
** Ex02
*/

#include <stdint.h>
#include <stdio.h>

typedef struct __attribute__((packed)) bmp_header_s {
    int16_t magic;
    int32_t size;
    int16_t _app1;
    int16_t _app2;
    int32_t offset;
} bmp_header_t;

typedef struct __attribute__((packed)) bmp_info_header_s {
    int32_t size;
    int32_t width;
    int32_t height;
    int16_t planes;
    int16_t bpp;
    int32_t compression;
    int32_t raw_data_size;
    int32_t h_resolution;
    int32_t v_resolution;
    int32_t palette_size;
    int32_t important_colors;
} bmp_info_header_t;

void make_bmp_header(bmp_header_t *header , size_t size);
void make_bmp_info_header(bmp_info_header_t *header , size_t size);


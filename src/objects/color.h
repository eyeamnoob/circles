#ifndef __MY_COLOR_H

#define __MY_COLOR_H

#include <stdint.h>

typedef struct __Color
{
    uint8_t r;
    uint8_t g;
    uint8_t b;
} Color;

Color init_color(uint8_t r, uint8_t g, uint8_t b)
{
    Color color = {0};

    color.r = r;
    color.g = g;
    color.b = b;

    return color;
}

#endif
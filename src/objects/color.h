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

Color mix_color(Color color1, Color color2)
{
    uint8_t red = (color1.r + color2.r) / 2;
    uint8_t green = (color1.g + color2.g) / 2;
    uint8_t blue = (color1.b + color2.b) / 2;

    return (Color){red, green, blue};
}

#endif
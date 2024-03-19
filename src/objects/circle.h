#ifndef __MY_CIRCLE_H
#define __MY_CIRCLE_H

#include <stdint.h>
#include "color.h"

typedef struct __Circle
{
    float radius;
    uint32_t x;
    uint32_t y;
    Color color;
} Circle;

void print_circle(Circle *circle)
{
    printf("Circle:\n");
    printf("  Radius: %.2f\n", circle->radius);
    printf("  Color: %u %u %u\n", circle->color.r, circle->color.g, circle->color.b);
}

Circle init_circle(float radius, uint32_t x, uint32_t y, Color color)
{
    Circle circle = {0};

    circle.radius = radius;
    circle.x = x;
    circle.y = y;
    circle.color = color;

    return circle;
}

#endif
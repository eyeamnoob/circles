#ifndef __MY_CIRCLE_H

#define __MY_CIRCLE_H

#include <stdint.h>
#include "color.h"

typedef struct __Circle
{
    float radius;
    Color color;
} Circle;

void print_circle(Circle *circle)
{
    printf("Circle:\n");
    printf("  Radius: %.2f\n", circle->radius);
    printf("  Color: %u %u %u\n", circle->color.r, circle->color.g, circle->color.b);
}

Circle init_circle(float radius, Color color)
{
    Circle circle = {0};

    circle.radius = radius;
    circle.color = color;

    return circle;
}

#endif
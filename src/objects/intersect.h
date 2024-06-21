#ifndef __MY_INTERSECT_H
#define __MY_INTERSECT_H

#include "circle.h"

typedef struct __Intersect
{
    Circle circle1;
    Circle circle2;
    Color color;

} Intersect;

Intersect init_intersect(Circle circle1, Circle circle2, Color color)
{
    Intersect intersect = {0};

    intersect.circle1 = circle1;
    intersect.circle2 = circle2;
    intersect.color = color;

    return intersect;
}

#endif
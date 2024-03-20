#include <stdio.h>
#include "objects/circle.h"
#include "objects/canvas.h"

int main(int argc, char const *argv[])
{
    Canvas canvas = init_canvas("ali.ppm", 800, 800, (Color){255, 255, 255});

    Color red = init_color(255, 0, 0);
    Color blue = init_color(0, 0, 255);

    Circle circle1 = init_circle(100, 400 - 50, 400, red);
    Circle circle2 = init_circle(100, 400 + 50, 400, blue);

    draw_circle(&canvas, circle1);
    draw_circle(&canvas, circle2);

    circles_intersect(&canvas, circle1, circle2);

    export_canvas(&canvas);

    return 0;
}

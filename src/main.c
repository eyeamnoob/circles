#include <stdio.h>
#include "objects/circle.h"
#include "objects/canvas.h"

int main(int argc, char const *argv[])
{
    Canvas canvas = init_canvas("ali.ppm", 800, 400, (Color){255, 255, 255});
    Color color = init_color(255, 0, 0);
    Circle circle = init_circle(30, 200, 200, color);

    draw_circle(&canvas, circle);

    export_canvas(&canvas);

    return 0;
}

#include <stdio.h>

#include "objects/canvas.h"
#include "objects/circle.h"
#include "objects/intersect.h"

#define CANVAS_HEIGHT 800
#define CANVAS_WIDTH 800

int main(int argc, char const *argv[])
{
	// Don't forget to free canvas!
	Canvas canvas = init_canvas("ali.ppm", CANVAS_HEIGHT, CANVAS_WIDTH, (Color){255, 255, 255});

	Color red = init_color(255, 0, 0);
	Color blue = init_color(0, 0, 255);
	Color green = init_color(0, 255, 0);

	Circle circle1 = init_circle(100, 100, 100, red);
	Circle circle2 = init_circle(100, 250, 100, blue);
	Color mixed_color = mix_color(circle1.color, circle2.color);

	Circle circle3 = init_circle(100, 100, 320, green);
	Circle circle4 = init_circle(100, 250, 320, green);

	Intersect intersect = init_intersect(circle1, circle2, mixed_color);

	draw_circle(&canvas, circle1);
	draw_circle(&canvas, circle2);
	draw_circle(&canvas, circle3);
	draw_circle(&canvas, circle4);
	draw_intersect(&canvas, intersect);

	export_canvas(&canvas);

	return 0;
}

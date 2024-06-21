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
	Color black = init_color(0, 0, 0);

	Circle circle1 = init_circle(100, 100, 100, red);
	Circle circle2 = init_circle(100, 250, 100, blue);
	Color mixed_color = mix_color(circle1.color, circle2.color);

	Intersect intersect = init_intersect(circle1, circle2, mixed_color);

	Circle circle3 = init_circle(100, 100, 320, green);
	Circle circle4 = init_circle(100, 250, 320, green);

	Circle circle5 = init_circle(100, 100, 540, black);

	// draw_circle(&canvas, circle1, true);
	// draw_circle(&canvas, circle2, true);
	draw_circle(&canvas, circle3, true);
	draw_circle(&canvas, circle4, true);
	draw_circle(&canvas, circle5, false);
	draw_intersect(&canvas, intersect, false);

	export_canvas(&canvas);

	return 0;
}

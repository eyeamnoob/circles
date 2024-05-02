#include <stdio.h>

#include "objects/canvas.h"
#include "objects/circle.h"
#include "objects/intersect.h"

int main(int argc, char const *argv[])
{
	// Don't forget to free canvas!
	Canvas canvas = init_canvas("ali.ppm", 800, 800, (Color){255, 255, 255});

	Color red = init_color(255, 0, 0);
	Color blue = init_color(0, 0, 255);

	Circle circle1 = init_circle(100, 400 - 50, 400, red);
	Circle circle2 = init_circle(100, 400 + 50, 400, blue);

	Intersect intersect = init_intersect(circle1, circle2, (Color){125, 125, 125});

	draw_circle(&canvas, circle1);
	draw_circle(&canvas, circle2);
	draw_intersect(&canvas, intersect);

	export_canvas(&canvas);

	return 0;
}

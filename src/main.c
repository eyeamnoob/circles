#include <stdio.h>

#include "objects/canvas.h"
#include "objects/circle.h"
#include "objects/intersect.h"

#define CANVAS_HEIGHT 800
#define CANVAS_WIDTH 800
#define SECTIONS 3

int main(int argc, char const *argv[])
{
	// Don't forget to free canvas!
	Canvas canvas = init_canvas("ali.ppm", CANVAS_HEIGHT, CANVAS_WIDTH, (Color){255, 255, 255});

	Color red = init_color(255, 0, 0);
	Color blue = init_color(0, 0, 255);
	Color green = init_color(0, 255, 0);
	Color black = init_color(0, 0, 0);
	Color white = init_color(255, 255, 255);

	const float CIRCLE_RADIUS = 100;
	const uint32_t SECTION_SIZE = CANVAS_HEIGHT / SECTIONS;
	const uint32_t PADDING = (SECTION_SIZE - CIRCLE_RADIUS * 2) / 2;

	Circle circle1 = init_circle(CIRCLE_RADIUS, 100, PADDING + CIRCLE_RADIUS + (SECTION_SIZE * 0), red);
	Circle circle2 = init_circle(CIRCLE_RADIUS, 250, PADDING + CIRCLE_RADIUS + (SECTION_SIZE * 0), blue);
	Color mixed_color1 = mix_color(circle1.color, circle2.color);
	Intersect intersect1 = init_intersect(circle1, circle2, mixed_color1);

	Circle circle3 = init_circle(CIRCLE_RADIUS, 100, PADDING + CIRCLE_RADIUS + (SECTION_SIZE * 1), green);
	Circle circle4 = init_circle(CIRCLE_RADIUS, 250, PADDING + CIRCLE_RADIUS + (SECTION_SIZE * 1), green);

	Circle circle5 = init_circle(CIRCLE_RADIUS, 100, PADDING + CIRCLE_RADIUS + (SECTION_SIZE * 2), black);

	Circle circle6 = init_circle(CIRCLE_RADIUS, 425, PADDING + CIRCLE_RADIUS + (SECTION_SIZE * 0), red);
	Circle circle7 = init_circle(CIRCLE_RADIUS, 550, PADDING + CIRCLE_RADIUS + (SECTION_SIZE * 0), blue);
	Intersect intersect2 = init_intersect(circle6, circle7, mixed_color1);

	Circle circle8 = init_circle(CIRCLE_RADIUS, 625, PADDING + CIRCLE_RADIUS + (SECTION_SIZE * 0), red);
	Circle circle9 = init_circle(CIRCLE_RADIUS, 750, PADDING + CIRCLE_RADIUS + (SECTION_SIZE * 0), blue);
	Intersect intersect3 = init_intersect(circle8, circle9, mixed_color1);

	Circle circle10 = init_circle(CIRCLE_RADIUS, 525, PADDING + CIRCLE_RADIUS + (SECTION_SIZE * 1), green);
	Circle circle11 = init_circle(CIRCLE_RADIUS, 650, PADDING + CIRCLE_RADIUS + (SECTION_SIZE * 1), green);
	Intersect intersect4 = init_intersect(circle10, circle11, white);

	draw_circle(&canvas, circle1, true);
	draw_circle(&canvas, circle2, true);
	draw_circle(&canvas, circle3, true);
	draw_circle(&canvas, circle4, true);
	draw_circle(&canvas, circle5, false);
	draw_circle(&canvas, circle10, false);
	draw_circle(&canvas, circle11, false);
	draw_intersect(&canvas, intersect1, true);
	draw_intersect(&canvas, intersect2, true);
	draw_intersect(&canvas, intersect3, false);
	draw_intersect(&canvas, intersect4, false);

	export_canvas(&canvas);

	return 0;
}

#ifndef __MY_CANVAS_H
#define __MY_CANVAS_H

#include "../utils/my_math.h"
#include "circle.h"
#include "color.h"
#include "intersect.h"

#include <math.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct __Canvas
{
    uint32_t x;
    uint32_t y;
    Color **surface;
    Color bg_color;
    char *name;
} Canvas;

static bool is_inside(Canvas *canvas, int32_t x, int32_t y)
{
    if (0 <= x && x < canvas->x)
    {
        if (0 <= y && y < canvas->y)
        {
            return true;
        }
    }
    return false;
}

void draw_circle(Canvas *canvas, Circle circle, bool fill)
{
    uint32_t x = circle.x;
    uint32_t y = circle.y;
    float radius = circle.radius;

    int32_t x_boundary_min = x - radius;
    int32_t x_boundary_max = x + radius;
    int32_t y_boundary_min = y - radius;
    int32_t y_boundary_max = y + radius;

    for (int32_t j = y_boundary_min; j <= y_boundary_max; ++j)
    {
        for (int32_t i = x_boundary_min; i <= x_boundary_max; ++i)
        {
            uint32_t dx = abs((int32_t)x - i);
            uint32_t dy = abs((int32_t)y - j);

            float distance = sqrt(dx * dx + dy * dy);
            if (fill && distance <= radius && is_inside(canvas, i, j))
            {
                canvas->surface[i][j] = circle.color;
            }
            else if (!fill && fabs(distance - radius) <= 1 && is_inside(canvas, i, j))
            {
                canvas->surface[i][j] = circle.color;
            }
        }
    }
}

static void draw_pixel(FILE *file, Color color)
{
    fputc(color.r, file);
    fputc(color.g, file);
    fputc(color.b, file);
}

void export_canvas(Canvas *canvas)
{
    FILE *file = fopen(canvas->name, "wb");
    if (file == NULL)
    {
        fprintf(stderr, "Cannot open canvas file: '%s'.\n", canvas->name);
        exit(1);
    }

    fprintf(file, "P6\n");
    fprintf(file, "%u %u\n", canvas->x, canvas->y);
    fprintf(file, "255\n");

    for (size_t j = 0; j < canvas->y; ++j)
    {
        for (size_t i = 0; i < canvas->x; ++i)
        {
            draw_pixel(file, canvas->surface[i][j]);
        }
    }
}

Canvas init_canvas(char *name, uint32_t x, uint32_t y, Color bg_color)
{
    Canvas canvas;
    canvas.name = name;
    canvas.x = x;
    canvas.y = y;
    canvas.bg_color = bg_color;

    canvas.surface = (Color **)malloc(sizeof(Color *) * x);
    for (size_t i = 0; i < x; ++i)
    {
        canvas.surface[i] = (Color *)malloc(sizeof(Color) * y);
    }

    for (size_t j = 0; j < canvas.y; ++j)
    {
        for (size_t i = 0; i < canvas.x; ++i)
        {
            canvas.surface[i][j] = bg_color;
        }
    }

    return canvas;
}

void draw_intersect(Canvas *canvas, Intersect intersect)
{
    Circle circle1 = intersect.circle1;
    Circle circle2 = intersect.circle2;

    int32_t circle1_top_left_x = circle1.x - circle1.radius;
    int32_t circle1_top_left_y = circle1.y - circle1.radius;
    int32_t circle1_bottom_right_x = circle1.x + circle1.radius;
    int32_t circle1_bottom_right_y = circle1.y + circle1.radius;

    int32_t circle2_top_left_x = circle2.x - circle2.radius;
    int32_t circle2_top_left_y = circle2.y - circle2.radius;
    int32_t circle2_bottom_right_x = circle2.x + circle2.radius;
    int32_t circle2_bottom_right_y = circle2.y + circle2.radius;

    int32_t intersect_rect_top_left_x = max(circle1_top_left_x, circle2_top_left_x);
    int32_t intersect_rect_top_left_y = max(circle1_top_left_y, circle2_top_left_y);
    int32_t intersect_rect_bottom_right_x = min(circle1_bottom_right_x, circle2_bottom_right_x);
    int32_t intersect_rect_bottom_right_y = min(circle1_bottom_right_y, circle2_bottom_right_y);

    for (int32_t j = intersect_rect_top_left_y; j <= intersect_rect_bottom_right_y; ++j)
    {
        for (int32_t i = intersect_rect_top_left_x; i <= intersect_rect_bottom_right_x; ++i)
        {
            uint32_t dx1 = abs((int32_t)circle1.x - i);
            uint32_t dy1 = abs((int32_t)circle1.y - j);
            float distance1 = sqrt(dx1 * dx1 + dy1 * dy1);

            uint32_t dx2 = abs((int32_t)circle2.x - i);
            uint32_t dy2 = abs((int32_t)circle2.y - j);
            float distance2 = sqrt(dx2 * dx2 + dy2 * dy2);

            if (distance1 <= circle1.radius && distance2 <= circle2.radius && is_inside(canvas, i, j))
            {
                canvas->surface[i][j] = intersect.color;
            }
        }
    }
}

#endif
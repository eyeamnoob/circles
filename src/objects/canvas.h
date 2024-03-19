#ifndef __MY_CANVAS_H
#define __MY_CANVAS_H

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "color.h"
#include "circle.h"

typedef struct __Canvas
{
    uint32_t x;
    uint32_t y;
    Color **surface;
    Color bg_color;
    char *name;
} Canvas;

void draw_circle(Canvas *canvas, Circle circle)
{
    uint32_t x = circle.x;
    uint32_t y = circle.y;
    float radius = circle.radius;

    uint32_t x_boundary_min = x - radius;
    uint32_t x_boundary_max = x + radius;
    uint32_t y_boundary_min = y - radius;
    uint32_t y_boundary_max = y + radius;

    for (size_t j = y_boundary_min; j <= y_boundary_max; ++j)
    {
        for (size_t i = x_boundary_min; i <= x_boundary_max; ++i)
        {
            uint32_t dx = abs(x - i);
            uint32_t dy = abs(y - j);

            float distance = sqrt(dx * dx + dy * dy);

            if (distance <= radius)
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

#endif
#ifndef CANVAS_H
#define CANVAS_H

#include <stdbool.h>
#include "shapes.h"

#define CANVAS_WIDTH 80
#define CANVAS_HEIGHT 24
#define MAX_OBJECTS 100

typedef struct Canvas {
    char pixels[CANVAS_HEIGHT][CANVAS_WIDTH];
} Canvas;

void init_canvas(Canvas *canvas);
void clear_canvas(Canvas *canvas);
void draw_canvas(const Canvas *canvas);
void set_pixel(Canvas *canvas, int x, int y, char ch);
void render_all_objects(Canvas *canvas, const Object objects[], int count);
bool inside_canvas(int x, int y);

#endif // CANVAS_H

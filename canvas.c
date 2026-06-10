#include <stdio.h>
#include "canvas.h"
#include "shapes.h"

void init_canvas(Canvas *canvas) {
    clear_canvas(canvas);
}

void clear_canvas(Canvas *canvas) {
    for (int y = 0; y < CANVAS_HEIGHT; y++) {
        for (int x = 0; x < CANVAS_WIDTH; x++) {
            canvas->pixels[y][x] = '_';
        }
    }
}

void draw_canvas(const Canvas *canvas) {
    for (int y = 0; y < CANVAS_HEIGHT; y++) {
        for (int x = 0; x < CANVAS_WIDTH; x++) {
            putchar(canvas->pixels[y][x]);
        }
        putchar('\n');
    }
}

void set_pixel(Canvas *canvas, int x, int y, char ch) {
    if (inside_canvas(x, y)) {
        canvas->pixels[y][x] = ch;
    }
}

bool inside_canvas(int x, int y) {
    return x >= 0 && x < CANVAS_WIDTH && y >= 0 && y < CANVAS_HEIGHT;
}

void render_all_objects(Canvas *canvas, const Object objects[], int count) {
    for (int i = 0; i < count; i++) {
        const Object *obj = &objects[i];
        switch (obj->type) {
            case SHAPE_LINE: draw_line(canvas, obj); break;
            case SHAPE_RECTANGLE: draw_rectangle(canvas, obj); break;
            case SHAPE_CIRCLE: draw_circle(canvas, obj); break;
            case SHAPE_TRIANGLE: draw_triangle(canvas, obj); break;
            default: break;
        }
    }
}

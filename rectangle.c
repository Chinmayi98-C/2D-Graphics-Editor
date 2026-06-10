#include "shapes.h"
#include "canvas.h"

static void draw_rectangle_edge(Canvas *canvas, int x1, int y1, int x2, int y2, char ch) {
    int left = x1 < x2 ? x1 : x2;
    int right = x1 < x2 ? x2 : x1;
    int top = y1 < y2 ? y1 : y2;
    int bottom = y1 < y2 ? y2 : y1;

    for (int x = left; x <= right; x++) {
        set_pixel(canvas, x, top, ch);
        set_pixel(canvas, x, bottom, ch);
    }
    for (int y = top; y <= bottom; y++) {
        set_pixel(canvas, left, y, ch);
        set_pixel(canvas, right, y, ch);
    }
}

void draw_rectangle(Canvas *canvas, const Object *obj) {
    draw_rectangle_edge(canvas, obj->x1, obj->y1, obj->x2, obj->y2, obj->marker);
}

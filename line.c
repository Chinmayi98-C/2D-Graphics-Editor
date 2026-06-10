#include <stdlib.h>
#include "shapes.h"
#include "canvas.h"

static void draw_line_segment(Canvas *canvas, int x0, int y0, int x1, int y1, char ch) {
    int dx = abs(x1 - x0);
    int dy = abs(y1 - y0);
    int sx = x0 < x1 ? 1 : -1;
    int sy = y0 < y1 ? 1 : -1;
    int err = dx - dy;

    while (true) {
        set_pixel(canvas, x0, y0, ch);
        if (x0 == x1 && y0 == y1) break;
        int e2 = err * 2;
        if (e2 > -dy) {
            err -= dy;
            x0 += sx;
        }
        if (e2 < dx) {
            err += dx;
            y0 += sy;
        }
    }
}

void draw_line(Canvas *canvas, const Object *obj) {
    draw_line_segment(canvas, obj->x1, obj->y1, obj->x2, obj->y2, obj->marker);
}

#include <math.h>
#include "shapes.h"
#include "canvas.h"

void draw_circle(Canvas *canvas, const Object *obj) {
    int x0 = obj->x1;
    int y0 = obj->y1;
    int radius = obj->radius;
    int x = radius;
    int y = 0;
    int err = 0;

    while (x >= y) {
        set_pixel(canvas, x0 + x, y0 + y, obj->marker);
        set_pixel(canvas, x0 + y, y0 + x, obj->marker);
        set_pixel(canvas, x0 - y, y0 + x, obj->marker);
        set_pixel(canvas, x0 - x, y0 + y, obj->marker);
        set_pixel(canvas, x0 - x, y0 - y, obj->marker);
        set_pixel(canvas, x0 - y, y0 - x, obj->marker);
        set_pixel(canvas, x0 + y, y0 - x, obj->marker);
        set_pixel(canvas, x0 + x, y0 - y, obj->marker);

        y++;
        if (err <= 0) {
            err += 2 * y + 1;
        }
        if (err > 0) {
            x--;
            err -= 2 * x + 1;
        }
    }
}

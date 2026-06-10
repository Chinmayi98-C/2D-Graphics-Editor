#ifndef SHAPES_H
#define SHAPES_H

#include <stdbool.h>

typedef struct Canvas Canvas;

typedef enum {
    SHAPE_LINE,
    SHAPE_RECTANGLE,
    SHAPE_CIRCLE,
    SHAPE_TRIANGLE,
    SHAPE_NONE
} ShapeType;

typedef struct {
    ShapeType type;
    int x1, y1;
    int x2, y2;
    int x3, y3;
    int radius;
    char marker;
} Object;

void draw_line(Canvas *canvas, const Object *obj);
void draw_rectangle(Canvas *canvas, const Object *obj);
void draw_circle(Canvas *canvas, const Object *obj);
void draw_triangle(Canvas *canvas, const Object *obj);

#endif // SHAPES_H

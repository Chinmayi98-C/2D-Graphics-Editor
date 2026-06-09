#include <stdio.h>
#include <stdlib.h>
#include "canvas.h"
#include "line.h"

void draw_line(int x1, int y1, int x2, int y2) {
    int dx = abs(x2 - x1);
    int dy = abs(y2 - y1);
    int sx = x1 < x2 ? 1 : -1;
    int sy = y1 < y2 ? 1 : -1;
    int err = dx - dy;

    while (1) {
        if (in_canvas(x1, y1)) {
            set_pixel(x1, y1, '*');
        }
        if (x1 == x2 && y1 == y2) break;
        int e2 = err * 2;
        if (e2 > -dy) {
            err -= dy;
            x1 += sx;
        }
        if (e2 < dx) {
            err += dx;
            y1 += sy;
        }
    }
}

void line_menu(void) {
    int x1, y1, x2, y2;

    printf("\n--- Line Menu ---\n");
    printf("Enter X1 (0-%d): ", canvas_width() - 1);
    scanf("%d", &x1);
    printf("Enter Y1 (0-%d): ", canvas_height() - 1);
    scanf("%d", &y1);
    printf("Enter X2 (0-%d): ", canvas_width() - 1);
    scanf("%d", &x2);
    printf("Enter Y2 (0-%d): ", canvas_height() - 1);
    scanf("%d", &y2);

    if (!in_canvas(x1, y1) || !in_canvas(x2, y2)) {
        printf("Line endpoints must be inside the canvas.\n");
        return;
    }

    draw_line(x1, y1, x2, y2);
    print_canvas();
}

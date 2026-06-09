#include <stdio.h>
#include "canvas.h"
#include "line.h"
#include "triangle.h"

void draw_triangle(int x1, int y1, int x2, int y2, int x3, int y3) {
    draw_line(x1, y1, x2, y2);
    draw_line(x2, y2, x3, y3);
    draw_line(x3, y3, x1, y1);
}

void triangle_menu(void) {
    int x1, y1, x2, y2, x3, y3;

    printf("\n--- Triangle Menu ---\n");
    printf("Enter X1 (0-%d): ", canvas_width() - 1);
    scanf("%d", &x1);
    printf("Enter Y1 (0-%d): ", canvas_height() - 1);
    scanf("%d", &y1);
    printf("Enter X2 (0-%d): ", canvas_width() - 1);
    scanf("%d", &x2);
    printf("Enter Y2 (0-%d): ", canvas_height() - 1);
    scanf("%d", &y2);
    printf("Enter X3 (0-%d): ", canvas_width() - 1);
    scanf("%d", &x3);
    printf("Enter Y3 (0-%d): ", canvas_height() - 1);
    scanf("%d", &y3);

    if (!in_canvas(x1, y1) || !in_canvas(x2, y2) || !in_canvas(x3, y3)) {
        printf("Triangle vertices must be inside the canvas.\n");
        return;
    }

    draw_triangle(x1, y1, x2, y2, x3, y3);
    print_canvas();
}

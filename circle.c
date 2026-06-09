#include <stdio.h>
#include <math.h>
#include "canvas.h"
#include "circle.h"

void draw_circle(int cx, int cy, int radius) {
    if (radius < 1) {
        return;
    }
    for (int y = cy - radius; y <= cy + radius; y++) {
        for (int x = cx - radius; x <= cx + radius; x++) {
            int dx = x - cx;
            int dy = y - cy;
            int dist2 = dx * dx + dy * dy;
            double dist = sqrt((double) dist2);
            if (dist >= radius - 0.5 && dist <= radius + 0.5) {
                set_pixel(x, y, '*');
            }
        }
    }
}

void circle_menu(void) {
    int cx, cy, radius;

    printf("\n--- Circle Menu ---\n");
    printf("Enter center X (0-%d): ", canvas_width() - 1);
    scanf("%d", &cx);
    printf("Enter center Y (0-%d): ", canvas_height() - 1);
    scanf("%d", &cy);
    printf("Enter radius (>=1): ");
    scanf("%d", &radius);

    if (radius < 1) {
        printf("Invalid radius.\n");
        return;
    }

    if (!in_canvas(cx, cy) || !in_canvas(cx + radius, cy) || !in_canvas(cx - radius, cy) || !in_canvas(cx, cy + radius) || !in_canvas(cx, cy - radius)) {
        printf("Circle does not fit on the canvas.\n");
        return;
    }

    draw_circle(cx, cy, radius);
    print_canvas();
}

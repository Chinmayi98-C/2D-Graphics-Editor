// Headers are required for I/O and canvas operations.
#include <stdio.h>
#include "canvas.h"
#include "rectangle.h"

void draw_rectangle(int x, int y, int width, int height) {
    int max_x = x + width - 1;
    int max_y = y + height - 1;

    for (int i = x; i <= max_x; i++) {
        set_pixel(i, y, '*');
        set_pixel(i, max_y, '*');
    }
    for (int j = y; j <= max_y; j++) {
        set_pixel(x, j, '*');
        set_pixel(max_x, j, '*');
    }
}

void rectangle_menu(void) {
    int x, y, width, height;

    printf("\n--- Rectangle Menu ---\n");
    printf("Enter top-left X (0-%d): ", canvas_width() - 1);
    scanf("%d", &x);
    printf("Enter top-left Y (0-%d): ", canvas_height() - 1);
    scanf("%d", &y);
    printf("Enter width (>=1): ");
    scanf("%d", &width);
    printf("Enter height (>=1): ");
    scanf("%d", &height);

    if (width < 1 || height < 1) {
        printf("Invalid size. Width and height must be at least 1.\n");
        return;
    }

    if (!in_canvas(x, y) || !in_canvas(x + width - 1, y + height - 1)) {
        printf("Rectangle does not fit on the canvas.\n");
        return;
    }

    draw_rectangle(x, y, width, height);
    print_canvas();
}

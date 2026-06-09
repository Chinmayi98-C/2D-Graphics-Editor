#include <stdio.h>
#include "canvas.h"

#define WIDTH 60
#define HEIGHT 20

static char canvas[HEIGHT][WIDTH + 1];

void clear_canvas(void) {
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            canvas[y][x] = '_';
        }
        canvas[y][WIDTH] = '\0';
    }
}

void print_canvas(void) {
    for (int y = 0; y < HEIGHT; y++) {
        printf("%s\n", canvas[y]);
    }
}

void set_pixel(int x, int y, char ch) {
    if (in_canvas(x, y)) {
        canvas[y][x] = ch;
    }
}

int canvas_width(void) {
    return WIDTH;
}

int canvas_height(void) {
    return HEIGHT;
}

int in_canvas(int x, int y) {
    return x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT;
}

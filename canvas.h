#ifndef CANVAS_H
#define CANVAS_H

void clear_canvas(void);
void print_canvas(void);
void set_pixel(int x, int y, char ch);
int canvas_width(void);
int canvas_height(void);
int in_canvas(int x, int y);

#endif // CANVAS_H

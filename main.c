#include <stdio.h>
#include "canvas.h"
#include "rectangle.h"
#include "circle.h"
#include "line.h"
#include "triangle.h"

int main() {
    clear_canvas();
    printf("========================================\n");
    printf("    2D ASCII Graphics Editor\n");
    printf("    Characters: * and _\n");
    printf("========================================\n");

    int choice;
    do {
        printf("\n--- Main Menu ---\n");
        printf("1. Draw Rectangle\n");
        printf("2. Draw Circle\n");
        printf("3. Draw Line\n");
        printf("4. Draw Triangle\n");
        printf("0. Quit\n");
        printf("Choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: rectangle_menu(); break;
            case 2: circle_menu();    break;
            case 3: line_menu();      break;
            case 4: triangle_menu();  break;
            case 0: printf("Goodbye!\n"); break;
            default: printf("Invalid choice, try again.\n");
        }
    } while (choice != 0);

    return 0;
}
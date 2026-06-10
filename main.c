#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "canvas.h"
#include "shapes.h"

static Object objects[MAX_OBJECTS];
static int object_count = 0;

static void print_menu(void) {
    puts("2D Graphics Editor");
    printf("Canvas size: %d x %d\n", CANVAS_WIDTH, CANVAS_HEIGHT);
    puts("1. Add object");
    puts("2. Delete object");
    puts("3. Modify object");
    puts("4. Display picture");
    puts("5. List objects");
    puts("0. Exit");
    printf("Enter choice: ");
}

static void print_shape_menu(void) {
    puts("Choose shape type:");
    puts("1. Line");
    puts("2. Rectangle");
    puts("3. Circle");
    puts("4. Triangle");
    printf("Enter shape type: ");
}

static const char *shape_name(ShapeType type) {
    switch (type) {
        case SHAPE_LINE: return "Line";
        case SHAPE_RECTANGLE: return "Rectangle";
        case SHAPE_CIRCLE: return "Circle";
        case SHAPE_TRIANGLE: return "Triangle";
        default: return "Unknown";
    }
}

static void add_object(void) {
    if (object_count >= MAX_OBJECTS) {
        puts("Object list is full.");
        return;
    }

    print_shape_menu();
    int choice;
    if (scanf("%d", &choice) != 1) {
        while (getchar() != '\n');
        puts("Invalid input.");
        return;
    }

    Object obj = {0};
    obj.marker = '*';
    switch (choice) {
        case 1:
            obj.type = SHAPE_LINE;
            printf("Enter x1 y1 x2 y2: ");
            if (scanf("%d %d %d %d", &obj.x1, &obj.y1, &obj.x2, &obj.y2) != 4) {
                puts("Invalid input.");
                return;
            }
            break;
        case 2:
            obj.type = SHAPE_RECTANGLE;
            printf("Enter x1 y1 x2 y2: ");
            if (scanf("%d %d %d %d", &obj.x1, &obj.y1, &obj.x2, &obj.y2) != 4) {
                puts("Invalid input.");
                return;
            }
            break;
        case 3:
            obj.type = SHAPE_CIRCLE;
            printf("Enter x1 y1 radius: ");
            if (scanf("%d %d %d", &obj.x1, &obj.y1, &obj.radius) != 3) {
                puts("Invalid input.");
                return;
            }
            break;
        case 4:
            obj.type = SHAPE_TRIANGLE;
            printf("Enter x1 y1 x2 y2 x3 y3: ");
            if (scanf("%d %d %d %d %d %d", &obj.x1, &obj.y1, &obj.x2, &obj.y2, &obj.x3, &obj.y3) != 6) {
                puts("Invalid input.");
                return;
            }
            break;
        default:
            puts("Invalid shape type.");
            return;
    }

    objects[object_count] = obj;
    printf("Object added with index %d.\n", object_count);
    object_count++;
}

static void delete_object(void) {
    if (object_count == 0) {
        puts("No objects to delete.");
        return;
    }
    printf("Enter object index to delete: ");
    int index;
    if (scanf("%d", &index) != 1 || index < 0 || index >= object_count) {
        puts("Invalid index.");
        return;
    }
    for (int i = index; i < object_count - 1; i++) {
        objects[i] = objects[i + 1];
    }
    object_count--;
    puts("Object deleted.");
}

static void modify_object(void) {
    if (object_count == 0) {
        puts("No objects to modify.");
        return;
    }
    printf("Enter object index to modify: ");
    int index;
    if (scanf("%d", &index) != 1 || index < 0 || index >= object_count) {
        puts("Invalid index.");
        return;
    }

    Object *obj = &objects[index];
    printf("Modifying object %d (%s)\n", index, shape_name(obj->type));
    switch (obj->type) {
        case SHAPE_LINE:
            printf("Enter x1 y1 x2 y2: ");
            if (scanf("%d %d %d %d", &obj->x1, &obj->y1, &obj->x2, &obj->y2) != 4) {
                puts("Invalid input.");
                return;
            }
            break;
        case SHAPE_RECTANGLE:
            printf("Enter x1 y1 x2 y2: ");
            if (scanf("%d %d %d %d", &obj->x1, &obj->y1, &obj->x2, &obj->y2) != 4) {
                puts("Invalid input.");
                return;
            }
            break;
        case SHAPE_CIRCLE:
            printf("Enter x1 y1 radius: ");
            if (scanf("%d %d %d", &obj->x1, &obj->y1, &obj->radius) != 3) {
                puts("Invalid input.");
                return;
            }
            break;
        case SHAPE_TRIANGLE:
            printf("Enter x1 y1 x2 y2 x3 y3: ");
            if (scanf("%d %d %d %d %d %d", &obj->x1, &obj->y1, &obj->x2, &obj->y2, &obj->x3, &obj->y3) != 6) {
                puts("Invalid input.");
                return;
            }
            break;
        default:
            puts("Unknown object type.");
            return;
    }
    puts("Object modified.");
}

static void list_objects(void) {
    if (object_count == 0) {
        puts("No objects in the picture.");
        return;
    }
    for (int i = 0; i < object_count; i++) {
        Object *obj = &objects[i];
        printf("%d: %s ", i, shape_name(obj->type));
        switch (obj->type) {
            case SHAPE_LINE:
                printf("(%d,%d)-(%d,%d)\n", obj->x1, obj->y1, obj->x2, obj->y2);
                break;
            case SHAPE_RECTANGLE:
                printf("(%d,%d)-(%d,%d)\n", obj->x1, obj->y1, obj->x2, obj->y2);
                break;
            case SHAPE_CIRCLE:
                printf("center=(%d,%d) radius=%d\n", obj->x1, obj->y1, obj->radius);
                break;
            case SHAPE_TRIANGLE:
                printf("(%d,%d)-(%d,%d)-(%d,%d)\n", obj->x1, obj->y1, obj->x2, obj->y2, obj->x3, obj->y3);
                break;
            default:
                puts("Unknown");
                break;
        }
    }
}

int main(void) {
    Canvas canvas;
    init_canvas(&canvas);

    while (1) {
        print_menu();
        int choice;
        if (scanf("%d", &choice) != 1) {
            while (getchar() != '\n');
            puts("Invalid choice.");
            continue;
        }

        switch (choice) {
            case 1:
                add_object();
                break;
            case 2:
                delete_object();
                break;
            case 3:
                modify_object();
                break;
            case 4:
                clear_canvas(&canvas);
                render_all_objects(&canvas, objects, object_count);
                draw_canvas(&canvas);
                break;
            case 5:
                list_objects();
                break;
            case 0:
                puts("Goodbye!");
                return 0;
            default:
                puts("Invalid choice.");
                break;
        }
    }
}

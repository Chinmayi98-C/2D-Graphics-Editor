# 2D Graphics Editor

A terminal-based 2D graphics editor written in C that allows you to create, modify, and display simple 2D shapes on a canvas.

## Features

- **Draw Shapes**: Create lines, rectangles, circles, and triangles
- **Add Objects**: Add multiple shapes to the canvas
- **Delete Objects**: Remove shapes by index
- **Modify Objects**: Edit existing shapes and their parameters
- **List Objects**: View all objects with their properties
- **Display Picture**: Render the complete picture on an 80x24 character canvas
- **Simple UI**: Interactive menu-driven interface in the terminal

## Canvas

- Size: 80 characters wide × 24 characters tall
- Background: `_` (underscore)
- Drawing character: `*` (asterisk)

## Building

Compile the project using GCC:

```bash
gcc main.c canvas.c line.c rectangle.c circle.c triangle.c -o graphics_editor
```

## Running

Execute the compiled program:

```bash
./graphics_editor.exe
```

(On Linux/Mac, use `./graphics_editor`)

## Usage

### Main Menu

```
2D Graphics Editor
Canvas size: 80 x 24
1. Add object
2. Delete object
3. Modify object
4. Display picture
5. List objects
0. Exit
Enter choice:
```

### Adding Objects

#### Line
- Input: `x1 y1 x2 y2`
- Example: `0 0 15 10`
- Draws a line from (x1, y1) to (x2, y2)

#### Rectangle
- Input: `x1 y1 x2 y2`
- Example: `5 3 25 12`
- Draws a rectangle with corners at (x1, y1) and (x2, y2)

#### Circle
- Input: `x1 y1 radius`
- Example: `40 12 8`
- Draws a circle at center (x1, y1) with specified radius

#### Triangle
- Input: `x1 y1 x2 y2 x3 y3`
- Example: `10 5 30 5 20 15`
- Draws a triangle with vertices at the three points

### Example Session

```
1. Add object
4. Triangle
10 5 30 5 20 15
Object added with index 0.

4. Display picture
(Shows the triangle on canvas)

5. List objects
0: Triangle (10,5)-(30,5)-(20,15)

0. Exit
Goodbye!
```

## Project Structure

- `main.c` - Main program with menu and object management
- `canvas.h / canvas.c` - Canvas initialization, rendering, and pixel operations
- `shapes.h` - Shape definitions and function declarations
- `line.c` - Line drawing implementation (Bresenham's algorithm)
- `rectangle.c` - Rectangle drawing implementation
- `circle.c` - Circle drawing implementation (Midpoint algorithm)
- `triangle.c` - Triangle drawing implementation

## Maximum Objects

The editor supports up to 100 objects on the canvas.

## Coordinate System

- X-axis: 0 to 79 (left to right)
- Y-axis: 0 to 23 (top to bottom)

## Requirements

- C compiler (GCC)
- Standard C library

## License

This is an educational project.

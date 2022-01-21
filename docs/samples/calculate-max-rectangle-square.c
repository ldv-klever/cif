/* This is a very simple program that finds out a rectangle with a maximum square from a provided list of rectangle
   heights and widths. It is intended only for demonstration of CIF capabilities. Please, do not use it anywhere since
   it contains several issues.
   The program expects the following input:
       height1 width1 height2 width2 ... heightN widthN
   where heighti and widthi should be integers representing respectively height and width of ith rectangle. */
#include <stdio.h>
#include <stdlib.h>

#define MAX(a, b) (a > b ? a : b)

struct rectangle
{
    unsigned int height;
    unsigned int width;
    unsigned int square;
};

unsigned int calculate_rectangle_square(struct rectangle *r)
{
    r->square = r->height * r->width;
    return r->square;
}

int main(int argc, const char *argv[])
{
    unsigned int rectangles_num;
    struct rectangle *rectangles;
    unsigned int cur_max_rectangle_square = 0;

    rectangles_num = (unsigned int)(argc / 2);
    rectangles = calloc(rectangles_num, sizeof(*rectangles));

    for (int i = 0; i < rectangles_num; i++) {
        struct rectangle *cur_rectangle = rectangles + i;
        cur_rectangle->height = atoi(argv[2 * i + 1]);
        cur_rectangle->width = atoi(argv[2 * i + 2]);
        calculate_rectangle_square(cur_rectangle);
        cur_max_rectangle_square = MAX(cur_max_rectangle_square, cur_rectangle->square);
    }

    printf("Maximum rectangle square is %u\n", cur_max_rectangle_square);

    return 0;
}

#include <stdio.h>
#include "objects/circle.h"

int main(int argc, char const *argv[])
{
    Color color = init_color(10, 15, 20);

    Circle circle = init_circle(35.76, color);

    print_circle(&circle);

    return 0;
}

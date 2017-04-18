
#include "line.hpp"
#include <stdio.h>

void Line::draw(void) const {
    printf("<line>\n");
    printf("%.2f, %.2f\n", this->p1.x, this->p1.y);
    printf("%.2f, %.2f\n", this->p2.x, this->p2.y);
    printf("</line>\n");
}

#include <GL/glut.h>

#include "polygon.hpp"

int main(int argc, char *argv[]) {
    Polygon p(
        {
            {1, 1},
            {0, .5f},
            {0, 0}
        }
    );
    p.draw();
    return 0;
}

#include <GL/glut.h>

#include "polygon.hpp"
#include "line.hpp"

int main(int argc, char *argv[])
{
    Polygon p(
        {
            {1, 1},
            {0, .5f},
            {0, 0}
        }
    );
    p.draw();

    Line l(
        0, 0,
        1, 2
    );
    l.draw();
    return 0;
}

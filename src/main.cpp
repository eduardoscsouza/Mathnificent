#include <GL/glut.h>

#include <cstdio>
#include <cmath>

#include "core/polygon.hpp"
#include "core/line.hpp"

#define N 10

Drawable *d;

using namespace std;

void render(void) {
    glLoadIdentity();
    glClear(GL_COLOR_BUFFER_BIT);
    d->draw();

    glFlush();
}

int main(int argc, char *argv[])
{
    vector<Point> v;
    for (int i = 0; i < 3*N; i++)
        v.push_back(
            {
                (float) (1.f/(1+i) * cos(2*i * M_PI/N)),
                (float) (1.f/(1+i) * sin(2*i * M_PI/N))
            }
        );

    d = new Line(v);

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGBA);
    glutCreateWindow("Test");

    glutInitWindowSize(500, 500);
    gluOrtho2D(-1, 1, -1, 1);

    glClearColor(.05f, .05f, .05f, 1.f);
    glutDisplayFunc(&render);

    glutMainLoop();

    delete d;

    return 0;
}

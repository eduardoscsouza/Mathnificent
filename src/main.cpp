#include <GL/glut.h>

#include <cstdio>
#include <cmath>

#include "polygon.hpp"
#include "line.hpp"

#define N 10

Polygon *p;

using namespace std;

void render(void) {
    glLoadIdentity();
    glClear(GL_COLOR_BUFFER_BIT);
    p->draw();

    glFlush();
}

int main(int argc, char *argv[])
{
    vector<Point> v;
    for (int i = 0; i < N; i++)
        v.push_back({(float) cos(2*i * M_PI/N), (float) sin(2*i * M_PI/N)});
    p = new Polygon(v, true);

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGBA);
    glutCreateWindow("Test");

    glutInitWindowSize(500, 500);
    gluOrtho2D(-1, 1, -1, 1);

    glClearColor(.05f, .05f, .05f, 1.f);
    glutDisplayFunc(&render);

    glutMainLoop();

    delete p;

    return 0;
}

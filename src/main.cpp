#include <GL/glut.h>

#include <cstdio>
#include <cmath>

#include "draw/line.hpp"
#include "draw/group.hpp"
#include "draw/polygon.hpp"

#define N 10

Group *scene;

using namespace std;

void render(void)
{
    glLoadIdentity();
    glClear(GL_COLOR_BUFFER_BIT);
    scene->draw();

    glFlush();
}

int main(int argc, char *argv[])
{
    vector<Vector> v;
    for (int i = 0; i < 3*N; i++)
        v.push_back(
            {
                (float) (1.f/(1+i) * cos(2*i * M_PI/N)),
                (float) (1.f/(1+i) * sin(2*i * M_PI/N))
            }
        );

    scene = new Group({new Line(v)});

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGBA);
    glutCreateWindow("Test");

    glutInitWindowSize(500, 500);
    gluOrtho2D(-1, 1, -1, 1);

    glClearColor(.05f, .05f, .05f, 1.f);
    glutDisplayFunc(&render);

    glutMainLoop();

    scene->destroyObjects();
    delete scene;

    return 0;
}

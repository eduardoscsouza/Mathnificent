#include <GL/glut.h>

#include <cstdio>
#include <cmath>

#include "draw/line.hpp"
#include "draw/group.hpp"
#include "draw/polygon.hpp"

#define N 300
#define TURNS 3

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
    for (int i = 0; i < N*TURNS; i++)
        v.push_back(
            {
                (float) (exp((float)-i/(N)) * cos(i * 2*M_PI*TURNS / N)),
                (float) (exp((float)-i/(N)) * sin(i * 2*M_PI*TURNS / N))
            }
        );

    scene = new Group({new Line(v)});

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGBA);

    glutInitWindowSize(500, 500);
    gluOrtho2D(-1, 1, -1, 1);

    glutCreateWindow("Test");

    glClearColor(.05f, .05f, .05f, 1.f);
    glutDisplayFunc(&render);

    glutMainLoop();

    scene->destroyObjects();
    delete scene;

    return 0;
}

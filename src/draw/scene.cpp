#include <GL/glut.h>
#include <functional>

#include "draw/scene.hpp"
#include "draw/group.hpp"

using namespace std;

Group *Scene::objects;

static float xmin = -1;
static float xmax = 1;
static float ymin = -1;
static float ymax = 1;

void Scene::init(void)
{
    int argc = 0;
    Scene::init(&argc, nullptr);
}

void Scene::init(int *argc, char *argv[])
{
    objects = new Group();

    glutInit(argc, argv);
    glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE);
}

void Scene::setCoordsLim(float x, float X, float y, float Y)
{
    xmin = x;
    xmax = X;
    ymin = y;
    ymax = Y;
}

void Scene::draw(void)
{
    objects->draw();
    glutSwapBuffers();
    glFlush();
}

void Scene::start(const char *title)
{
    glutInitWindowSize(500, 500);
    glutCreateWindow(title);

    gluOrtho2D(xmin, xmax, ymin, ymax);
    glutDisplayFunc(&Scene::draw);
    glutMainLoop();
}

void Scene::cleanup(bool destroyObjects)
{
    if (destroyObjects)
        objects->destroyObjects();
    delete objects;
}

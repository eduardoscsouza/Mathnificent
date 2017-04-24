#include <GL/glut.h>
#include <functional>

#include "draw/scene.hpp"
#include "draw/group.hpp"

using namespace std;

static Group *scene;

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
    scene = new Group();

    glutInit(argc, argv);
    glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE);

    glutInitWindowSize(500, 500);
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
    scene->draw();
    glutSwapBuffers();
    glFlush();
}

void Scene::start(const char *title)
{
    gluOrtho2D(xmin, xmax, ymin, ymax);
    glutCreateWindow(title);

    gluOrtho2D(xmin, xmax, ymin, ymax);
    glutDisplayFunc(&Scene::draw);
    glutMainLoop();
}

void Scene::add(Drawable *d)
{
    scene->add(d);
}

void Scene::add(const vector<Drawable*>& obj)
{
    scene->add(obj);
}

void Scene::destroyObjects(void)
{
    scene->destroyObjects();
}

void Scene::cleanup(void)
{
    delete scene;
}

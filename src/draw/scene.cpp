#include <GL/glut.h>
#include <functional>

#include "draw/scene.hpp"
#include "draw/group.hpp"

#include <cstdio>

using namespace std;

static Group *scene;

void Scene::init(void)
{
    scene = new Group();
}

void Scene::draw(void)
{
    scene->draw();
    glFlush();
}

void Scene::start(const char *title)
{
    int argc = 0;
    Scene::start(title, &argc, nullptr);
}

void Scene::start(const char *title, int *argc, char *argv[])
{
    glutInit(argc, argv);
    glutInitDisplayMode(GLUT_RGBA);

    glutInitWindowSize(500, 500);
    gluOrtho2D(-1, 1, -1, 1);
    glutCreateWindow(title);

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

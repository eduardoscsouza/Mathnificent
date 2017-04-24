#include <GL/glut.h>
#include <functional>

#include "draw/scene.hpp"
#include "draw/group.hpp"

using namespace std;

static Group *scene;

void Scene::init(void)
{
    int argc = 0;
    Scene::init(&argc, nullptr);
}

void Scene::init(int *argc, char *argv[])
{
    scene = new Group();

    glutInit(argc, argv);
    glutInitDisplayMode(GLUT_RGBA);

    glutInitWindowSize(500, 500);
}

void Scene::draw(void)
{
    scene->draw();
    glFlush();
}

void Scene::start(const char *title)
{
    glutCreateWindow(title);

    gluOrtho2D(-1, 1, -1, 1);
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

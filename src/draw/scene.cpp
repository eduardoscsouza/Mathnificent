#include <GL/glut.h>
#include <functional>
#include <chrono>

#include "draw/scene.hpp"
#include "draw/group.hpp"

using namespace std;

using Clock = std::chrono::steady_clock;

Group *Scene::objects;

static float xmin = -1;
static float xmax = 1;
static float ymin = -1;
static float ymax = 1;

static chrono::time_point<Clock> frameStart;

static float t;

void updateScene(void)
{
    chrono::time_point<Clock> frameEnd = Clock::now();

    chrono::milliseconds d = chrono::duration_cast<chrono::milliseconds>(frameEnd - frameStart);
    float dt = d.count() / 1000.f;
    t += dt;

    Scene::objects->update(t, dt);

    glutPostRedisplay();
}

void preDrawScene(void)
{
    frameStart = Clock::now();
}

void drawScene(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    Scene::objects->draw();
    glutSwapBuffers();
}

void Scene::init(void)
{
    int argc = 0;
    Scene::init(&argc, nullptr);
}

void Scene::init(int *argc, char *argv[])
{
    objects = new Group(nullptr, &preDrawScene);
    t = 0;

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

void Scene::start(const char *title)
{
    glutInitWindowSize(500, 500);
    glutCreateWindow(title);

    gluOrtho2D(xmin, xmax, ymin, ymax);
    glutDisplayFunc(&drawScene);
    glutIdleFunc(&updateScene);
    glutMainLoop();
}

void Scene::cleanup(bool destroyObjects)
{
    if (destroyObjects)
        objects->destroyObjects();
    delete objects;
}

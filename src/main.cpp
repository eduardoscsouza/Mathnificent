#include <GL/glut.h>

#include <cstdio>
#include <cmath>

#include "draw/line.hpp"
#include "draw/group.hpp"
#include "draw/polygon.hpp"
#include "draw/scene.hpp"

#define N 300

using namespace std;

int main(int argc, char *argv[])
{
    vector<Vector> v;
    for (int i = 0; i < N; i++)
    {
        float t = (float) (2*M_PI * ((float)i/N));
        v.push_back
        (
            {
                (float) (2*cos(t) - cos(2*t)) / 4,
                (float) (2*sin(t) - sin(2*t)) / 4
            }
        );
    }

    Scene::init();
    Scene::add(new Line(v));

    Scene::start("Test");

    Scene::destroyObjects();
    Scene::cleanup();

    return 0;
}

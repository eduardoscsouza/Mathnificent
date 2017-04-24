#include <GL/glut.h>

#include <cstdio>
#include <cmath>

#include "draw/line.hpp"
#include "draw/group.hpp"
#include "draw/polygon.hpp"
#include "draw/scene.hpp"

#define M 3
#define N 300

using namespace std;

int main(int argc, char *argv[])
{
    vector<Vector> v;
    for (int i = 0; i < N*M; i++)
        v.push_back(
            {
                (float) (exp((float)-i/N) * cos(i * 2*M_PI*M / N)),
                (float) (exp((float)-i/N) * sin(i * 2*M_PI*M / N))
            }
        );

    Scene::init();
    Scene::add(new Line(v));

    Scene::start("Test");

    Scene::destroyObjects();
    Scene::cleanup();

    return 0;
}

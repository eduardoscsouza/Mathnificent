#include <GL/glut.h>

#include <cstdio>
#include <cmath>

#include <algorithm>

#include "draw/line.hpp"
#include "draw/group.hpp"
#include "draw/polygon.hpp"
#include "draw/scene.hpp"

#define N 300

#define DEG_PER_SEC 10.f

using namespace std;

int main(int argc, char *argv[])
{
    vector<Vector> points;
    for (int i = 0; i < N; i++)
    {
        float t = (float) (2*M_PI * ((float)i/N));
        points.push_back
        (
            {
                (float) (2*cos(t) - cos(2*t)),
                (float) (2*sin(t) - sin(2*t))
            }
        );
    }

    float angle = 0.f;

    Scene::init();
    Scene::setCoordsLim(-4, 4, -4, 4);

    Scene::objects->add(new Line(points,
        [&angle](float t, float dt)
        {
            angle = t*DEG_PER_SEC;
            cout << t << endl;
        },
        [angle](void)
        {
            cout << "predraw" << endl;
            glPushMatrix();
            glRotatef(angle, 0.f, 0.f, 1.f);
        },
        [](void)
        {
            cout << "postdraw" << endl;
            glPopMatrix();
        }
    ));

    Scene::start("Test");

    Scene::cleanup(true);

    return 0;
}

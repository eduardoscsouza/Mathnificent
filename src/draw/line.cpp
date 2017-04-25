#include <GL/gl.h>
#include <algorithm>

#include "draw/line.hpp"

using namespace std;

Line::Line(size_t nVectors, const Vector * const p, UpdateFunction update)
    : Drawable(update)
{
    for (size_t i = 0; i < nVectors; i++)
        this->points.push_back(p[i]);
}

Line::Line(const vector<Vector>& p, UpdateFunction update)
    : Drawable(update)
{
    this->points = vector<Vector>(p);
}

Line::Line(initializer_list<Vector> p, UpdateFunction update)
    : Drawable(update)
{
    this->points = vector<Vector>(p);
}

void Line::draw(void) const
{
    glBegin(GL_LINE_STRIP);
        for_each(
            this->points.begin(),
            this->points.end(),
            [](Vector p)
            {
                glVertex3f(p.x, p.y, p.z);
            }
        );
    glEnd();
}

Vector& Line::operator[](int i)
{
    return this->points[i];
}

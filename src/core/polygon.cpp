#include <GL/gl.h>
#include <algorithm>

#include "core/polygon.hpp"

using namespace std;

Polygon::Polygon(size_t nPoints, const Point * const p, bool fill)
{
    for (size_t i = 0; i < nPoints; i++)
        this->vertices.push_back(p[i]);
    this->fill = fill;
}

Polygon::Polygon(const vector<Point>& p, bool fill)
{
    this->vertices = vector<Point>(p);
    this->fill = fill;
}

void Polygon::draw(void) const
{
    glBegin(this->fill ? GL_POLYGON : GL_LINE_STRIP);
        for_each(
            this->vertices.begin(),
            this->vertices.end(),
            [](Point p)
            {
                glVertex3f(p.x, p.y, p.z);
            }
        );
        glVertex3f(this->vertices[0].x, this->vertices[0].y, this->vertices[0].z);
    glEnd();
}

Point& Polygon::operator[](int i)
{
    return this->vertices[i];
}

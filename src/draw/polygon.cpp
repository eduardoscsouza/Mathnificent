#include <GL/gl.h>
#include <algorithm>

#include "draw/polygon.hpp"

using namespace std;

Polygon::Polygon(size_t nVectors, const Vector * const p, bool fill, UpdateFunction update)
    : Drawable(update)
{
    for (size_t i = 0; i < nVectors; i++)
        this->vertices.push_back(p[i]);
    this->fill = fill;
}

Polygon::Polygon(const vector<Vector>& p, bool fill, UpdateFunction update)
    : Drawable(update)
{
    this->vertices = vector<Vector>(p);
    this->fill = fill;
}

Polygon::Polygon(initializer_list<Vector> p, bool fill, UpdateFunction update)
    : Drawable(update)
{
    this->vertices = vector<Vector>(p);
    this->fill = fill;
}

void Polygon::draw(void) const
{
    glBegin(this->fill ? GL_POLYGON : GL_LINE_STRIP);
        for_each(
            this->vertices.begin(),
            this->vertices.end(),
            [](Vector p)
            {
                glVertex3f(p.x, p.y, p.z);
            }
        );
        glVertex3f(this->vertices[0].x, this->vertices[0].y, this->vertices[0].z);
    glEnd();
}

Vector& Polygon::operator[](int i)
{
    return this->vertices[i];
}

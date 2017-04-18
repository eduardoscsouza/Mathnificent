#include <GL/glut.h>
#include <algorithm>

#include "line.hpp"

using namespace std;

Line::Line(size_t nPoints, const Point * const p)
{
    for (size_t i = 0; i < nPoints; i++)
        this->points.push_back(p[i]);
}

Line::Line(const vector<Point>& p)
{
    this->points = vector<Point>(p);
}

void Line::draw(void) const
{
    glBegin(GL_LINE_STRIP);
        for_each(
            this->points.begin(),
            this->points.end(),
            [](Point p)
            {
                glVertex3f(p.x, p.y, p.z);
            }
        );
    glEnd();
}

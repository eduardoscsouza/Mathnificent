#include "polygon.hpp"

#include <algorithm>
#include <stdio.h>

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
    printf("<polygon");
    if (this->fill)
        printf(" fill=true");
    printf(">\n");
    for_each(
        this->vertices.begin(),
        this->vertices.end(),
        [](const Point& p)
        {
            printf("%.2f, %.2f\n", p.x, p.y);
        }
    );
    printf("</polygon>\n");
}

Point& Polygon::operator[](int i) {
    return this->vertices[i];
}

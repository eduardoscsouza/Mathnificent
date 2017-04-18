#include "polygon.hpp"

#include <algorithm>
#include <stdio.h>

using namespace std;

Polygon::Polygon(size_t nPoints, Point *p, bool fill)
{
    for (size_t i = 0; i < nPoints; i++)
        this->points.push_back(p[i]);
    this->fill = fill;
}

Polygon::Polygon(const vector<Point>& p, bool fill)
{
    this->points = vector<Point>(p);
    this->fill = fill;
}

void Polygon::draw(void) const
{
    printf("<polygon");
    if (this->fill)
        printf(" fill=true");
    printf(">\n");
    for_each(
        this->points.begin(),
        this->points.end(),
        [](const Point& p)
        {
            printf("%.2f, %.2f\n", p.x, p.y);
        }
    );
    printf("</polygon>\n");
}

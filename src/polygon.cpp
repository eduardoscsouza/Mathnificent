#include "polygon.hpp"

#include <algorithm>
#include <stdio.h>

using namespace std;

Polygon::Polygon(size_t nPoints, Point *p)
{
    for (size_t i = 0; i < nPoints; i++)
        this->points.push_back(p[i]);
}

Polygon::Polygon(const vector<Point>& p)
{
    this->points = vector<Point>(p);
}

void Polygon::draw(void) const
{
    for_each(
        this->points.begin(),
        this->points.end(),
        [](const Point& p)
        {
            printf("%.2f, %.2f\n", p.x, p.y);
        }
    );
}

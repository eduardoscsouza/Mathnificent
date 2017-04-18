
#ifndef LINE_HPP
#define LINE_HPP 1

#include "point.hpp"
#include "drawable.hpp"

class Line : public Drawable
{
    public:
        const Point p1;
        const Point p2;

        Line(const Point& p1, const Point& p2) : p1(p1), p2(p2) {}
        Line(float x1, float y1, float x2, float y2) : p1(Point(x1, y1)), p2(Point(x2, y2)) {}

        void draw(void) const override;
};

#endif

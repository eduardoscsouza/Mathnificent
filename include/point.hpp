
#ifndef POINT_HPP
#define POINT_HPP 1

class Point {
    public:
        const float x;
        const float y;

        Point(float x, float y) : x(x), y(y) {}
        Point(const Point& p) : x(p.x), y(p.y) {}
};

#endif

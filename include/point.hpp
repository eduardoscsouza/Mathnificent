
#ifndef POINT_HPP
#define POINT_HPP 1

class Point
{
    public:
        float x;
        float y;
        float z;

        Point(float x, float y, float z=0) : x(x), y(y), z(z) {}
        Point(const Point& p) : x(p.x), y(p.y), z(p.z) {}
};

#endif

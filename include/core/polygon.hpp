
#ifndef POLYGON_HPP
#define POLYGON_HPP 1

#include <vector>
#include <initializer_list>

#include "core/drawable.hpp"
#include "core/point.hpp"

class Polygon: public Drawable
{
    private:
        std::vector<Point> vertices;

    public:
        bool fill;

        Polygon(std::size_t nPoints, const Point * const p, bool fill=false);
        Polygon(const std::vector<Point>& p, bool fill=false);
        Polygon(std::initializer_list<Point> p, bool fill=false);

        void draw(void) const override;
        Point& operator[](int i);
};


#endif


#ifndef POLYGON_HPP
#define POLYGON_HPP 1

#include <vector>

#include "drawable.hpp"
#include "point.hpp"

class Polygon: public Drawable
{
    private:
        std::vector<Point> vertices;
        bool fill;

    public:
        Polygon(std::size_t nPoints, Point *p, bool fill=false);
        Polygon(const std::vector<Point>& p, bool fill=false);

        void draw(void) const override;
};


#endif

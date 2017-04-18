
#ifndef POLYGON_HPP
#define POLYGON_HPP 1

#include <vector>

#include "drawable.hpp"
#include "point.hpp"

class Polygon: public Drawable {
    private:
        std::vector<Point> points;

    public:
        Polygon(std::size_t nPoints, Point *p);
        Polygon(const std::vector<Point>& p);

        void draw(void) const override;
};


#endif


#ifndef LINE_HPP
#define LINE_HPP 1

#include <vector>
#include <initializer_list>

#include "core/point.hpp"
#include "core/drawable.hpp"

class Line : public Drawable
{
    private:
        std::vector<Point> points;

    public:
        Line(std::size_t nPoints, const Point * const p);
        Line(const std::vector<Point>& p);
        Line(std::initializer_list<Point> p);

        void draw(void) const override;
};

#endif

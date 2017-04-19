
#ifndef LINE_HPP
#define LINE_HPP 1

#include <vector>
#include <initializer_list>

#include "draw/vec.hpp"
#include "draw/drawable.hpp"

class Line : public Drawable
{
    private:
        std::vector<Vector> points;

    public:
        Line(std::size_t nVectors, const Vector * const p);
        Line(const std::vector<Vector>& p);
        Line(std::initializer_list<Vector> p);

        void draw(void) const override;
};

#endif

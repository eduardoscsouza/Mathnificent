
#ifndef LINE_HPP
#define LINE_HPP 1

#include <vector>
#include <initializer_list>

#include "core/vec.hpp"
#include "draw/drawable.hpp"

class Line : public Drawable
{
    private:
        std::vector<Vector> points;

    public:
        Line(std::size_t nVectors, const Vector * const p, UpdateFunction update=nullptr, PreDrawFunction preDraw=nullptr);
        Line(const std::vector<Vector>& p, UpdateFunction update=nullptr, PreDrawFunction preDraw=nullptr);
        Line(std::initializer_list<Vector> p, UpdateFunction update=nullptr, PreDrawFunction preDraw=nullptr);

        void draw(void) const override;
        Vector& operator[](int i);
};

#endif

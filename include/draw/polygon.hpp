
#ifndef POLYGON_HPP
#define POLYGON_HPP 1

#include <vector>
#include <initializer_list>

#include "core/vec.hpp"
#include "draw/drawable.hpp"


#define POLY_DEFAULT_FILL true

class Polygon: public Drawable
{
    private:
        std::vector<Vector> vertices;

    public:
        bool fill;

        Polygon(std::size_t nVectors, const Vector * const p, bool fill=POLY_DEFAULT_FILL, UpdateFunction update=nullptr, PreDrawFunction preDraw=nullptr);
        Polygon(const std::vector<Vector>& p, bool fill=POLY_DEFAULT_FILL, UpdateFunction update=nullptr, PreDrawFunction preDraw=nullptr);
        Polygon(std::initializer_list<Vector> p, bool fill=POLY_DEFAULT_FILL, UpdateFunction update=nullptr, PreDrawFunction preDraw=nullptr);

        void draw(void) const override;
        Vector& operator[](int i);
};


#endif

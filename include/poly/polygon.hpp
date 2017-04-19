
#ifndef POLYGON_HPP
#define POLYGON_HPP 1

#include <vector>
#include <initializer_list>

#include "core/drawable.hpp"
#include "core/vec.hpp"


#define POLY_DEFAULT_FILL true

class Polygon: public Drawable
{
    private:
        std::vector<Vector> vertices;

    public:
        bool fill;

        Polygon(std::size_t nVectors, const Vector * const p, bool fill=POLY_DEFAULT_FILL);
        Polygon(const std::vector<Vector>& p, bool fill=POLY_DEFAULT_FILL);
        Polygon(std::initializer_list<Vector> p, bool fill=POLY_DEFAULT_FILL);

        void draw(void) const override;
        Vector& operator[](int i);
};


#endif

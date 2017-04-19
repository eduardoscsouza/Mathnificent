
#ifndef GROUP_HPP
#define GROUP_HPP 1

#include <vector>
#include <initializer_list>

#include "core/drawable.hpp"

class Group : public Drawable {
    private:
        std::vector<Drawable*> objects;

    public:
        Group(void) {}
        Group(const std::vector<Drawable*>& l);
        Group(std::initializer_list<Drawable*> l);

        void draw(void) const override;
        void add(Drawable *d);

        void destroyObjects(void);
};

#endif

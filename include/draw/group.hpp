
#ifndef GROUP_HPP
#define GROUP_HPP 1

#include <vector>
#include <initializer_list>

#include "draw/drawable.hpp"

class Group : public Drawable {
    private:
        std::vector<Drawable*> objects;

    public:
        Group(void) {}
        Group(const std::vector<Drawable*>& l, UpdateFunction update=nullptr);
        Group(std::initializer_list<Drawable*> l, UpdateFunction update=nullptr);

        void draw(void) const override;
        void add(Drawable *d);
        void add(const std::vector<Drawable*>& d);

        void destroyObjects(void);
};

#endif


#include "core/group.hpp"

#include <algorithm>

using namespace std;

Group::Group(const vector<Drawable>& l)
{
    this->objects = vector<Drawable>(l);
}

Group::Group(initializer_list<Drawable> l)
{
    this->objects = vector<Drawable>(l);
}

void Group::draw(void) const
{
    for_each(
        this->objects.begin(),
        this->objects.end(),
        [](const Drawable& d)
        {
            d.draw();
        }
    );
}

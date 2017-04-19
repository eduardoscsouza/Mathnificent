#include <GL/gl.h>
#include <algorithm>

#include "core/group.hpp"

using namespace std;

Group::Group(const vector<Drawable*>& l)
{
    this->objects = vector<Drawable*>(l);
}

Group::Group(initializer_list<Drawable*> l)
{
    this->objects = vector<Drawable*>(l);
}

void Group::draw(void) const
{
    for_each(
        this->objects.begin(),
        this->objects.end(),
        [](const Drawable *d)
        {
            d->draw();
        }
    );
}

void Group::add(Drawable *d)
{
    this->objects.push_back(d);
}

void Group::destroyObjects(void)
{
    for_each(
        this->objects.begin(),
        this->objects.end(),
        [](Drawable *d)
        {
            delete d;
        }
    );
}

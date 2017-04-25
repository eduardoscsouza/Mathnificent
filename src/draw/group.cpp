#include <GL/gl.h>
#include <algorithm>

#include "draw/group.hpp"

using namespace std;

Group::Group(const vector<Drawable*>& l, UpdateFunction update, PreDrawFunction preDraw)
    : Drawable(update, preDraw)
{
    this->objects = vector<Drawable*>(l);
}

Group::Group(initializer_list<Drawable*> l, UpdateFunction update, PreDrawFunction preDraw)
    : Drawable(update, preDraw)
{
    this->objects = vector<Drawable*>(l);
}

void Group::draw(void) const
{
    Drawable::draw();
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

void Group::add(const vector<Drawable*>& d)
{
    this->objects.insert(this->objects.end(), d.begin(), d.end());
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

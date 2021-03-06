#include <GL/gl.h>
#include <algorithm>

#include "draw/group.hpp"

using namespace std;

Group::Group(const vector<Drawable*>& l,
        UpdateFunction update,
        PreDrawFunction preDraw,
        PostDrawFunction postDraw)
    : Drawable(update, preDraw, postDraw)
{
    this->objects = vector<Drawable*>(l);
}

Group::Group(initializer_list<Drawable*> l,
        UpdateFunction update,
        PreDrawFunction preDraw,
        PostDrawFunction postDraw)
    : Drawable(update, preDraw, postDraw)
{
    this->objects = vector<Drawable*>(l);
}

void Group::draw(void) const
{
    this->preDraw();
    for_each(
        this->objects.begin(),
        this->objects.end(),
        [](const Drawable *d)
        {
            d->draw();
        }
    );
    this->postDraw();
}

void Group::update(float t, float dt)
{
    Drawable::update(t, dt);
    for_each(
        this->objects.begin(),
        this->objects.end(),
        [t, dt](Drawable *d)
        {
            d->update(t, dt);
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

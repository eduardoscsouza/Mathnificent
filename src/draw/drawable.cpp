#include "draw/drawable.hpp"

using namespace std;

void defaultUpdate(float t, float dt)
{
    (void) t;
    (void) dt;
}

void defaultPreDraw(void) {}

Drawable::Drawable(UpdateFunction update, PreDrawFunction preDraw)
{
    if (update == nullptr)
        update = &defaultUpdate;
    if (preDraw == nullptr)
        preDraw = &defaultPreDraw;

    this->updateFunc = update;
    this->preDrawFunc = preDraw;
}

void Drawable::update(float t, float dt)
{
    this->updateFunc(t, dt);
}

void Drawable::preDraw(void) const
{
    this->preDrawFunc();
}

void Drawable::draw(void) const
{
    this->preDraw();
}

#include "draw/drawable.hpp"

using namespace std;

void defaultUpdate(float t, float dt)
{
    (void) t;
    (void) dt;
}

void defaultPreDraw(void) {}
void defaultPostDraw(void) {}

Drawable::Drawable(
        UpdateFunction update,
        PreDrawFunction preDraw,
        PostDrawFunction postDraw)
{
    if (update == nullptr)
        update = &defaultUpdate;
    if (preDraw == nullptr)
        preDraw = &defaultPreDraw;
    if (postDraw == nullptr)
        postDraw = &defaultPostDraw;

    this->updateFunc = update;
    this->preDrawFunc = preDraw;
    this->postDrawFunc = postDraw;
}

void Drawable::update(float t, float dt)
{
    this->updateFunc(t, dt);
}

void Drawable::preDraw(void) const
{
    this->preDrawFunc();
}

void Drawable::postDraw(void) const
{
    this->postDrawFunc();
}

#include "draw/drawable.hpp"

void Drawable::update(float t, float dt)
{
    this->updateFunc(t, dt);
}

void Drawable::setUpdateFunc(UpdateFunction update)
{
    this->updateFunc = update;
}

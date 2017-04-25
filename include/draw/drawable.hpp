
#ifndef DRAWABLE_HPP
#define DRAWABLE_HPP 1

#include <functional>

#include <iostream>

class Drawable
{
    public:
        typedef std::function<void(float, float)> UpdateFunction;
        typedef std::function<void(void)> PreDrawFunction;

        Drawable(UpdateFunction update=nullptr, PreDrawFunction=nullptr);

        virtual void draw(void) const = 0;

        void preDraw(void) const;
        void update(float t, float dt);

    private:
        UpdateFunction updateFunc;
        PreDrawFunction preDrawFunc;
};

#endif

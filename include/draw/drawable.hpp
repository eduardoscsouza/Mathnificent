
#ifndef DRAWABLE_HPP
#define DRAWABLE_HPP 1

#include <functional>

#include <iostream>

class Drawable
{
    public:
        typedef std::function<void(float, float)> UpdateFunction;
        typedef std::function<void(void)> PreDrawFunction;
        typedef std::function<void(void)> PostDrawFunction;

        Drawable(UpdateFunction update=nullptr, PreDrawFunction=nullptr, PostDrawFunction=nullptr);

        virtual void draw(void) const = 0;
        virtual void update(float t, float dt);

        void preDraw(void) const;
        void postDraw(void) const;

    private:
        UpdateFunction updateFunc;
        PreDrawFunction preDrawFunc;
        PostDrawFunction postDrawFunc;
};

#endif

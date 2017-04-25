
#ifndef DRAWABLE_HPP
#define DRAWABLE_HPP 1

#include <functional>

class Drawable
{
    private:
        std::function<void(float, float)> updateFunc;

    public:
        typedef std::function<void(float, float)> UpdateFunction;

        Drawable(void) {}
        Drawable(UpdateFunction update) : updateFunc(update) {}

        virtual void draw(void) const = 0;
        void update(float t, float dt);
        void setUpdateFunc(UpdateFunction update);
};

#endif

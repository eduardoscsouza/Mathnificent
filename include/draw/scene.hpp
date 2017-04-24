
#ifndef SCENE_HPP
#define SCENE_HPP 1

#include <vector>

#include "draw/drawable.hpp"

namespace Scene
{
    void init(void);
    void init(int *argc, char *argv[]);

    void draw(void);

    void start(const char *title);

    void add(Drawable *d);
    void add(const std::vector<Drawable*>& d);

    void destroyObjects(void);
    void cleanup(void);
};

#endif


#ifndef SCENE_HPP
#define SCENE_HPP 1

#include <vector>

#include "draw/drawable.hpp"
#include "draw/group.hpp"

namespace Scene
{
    extern Group *objects;

    void init(void);
    void init(int *argc, char *argv[]);

    void setCoordsLim(float xmin, float xmax, float ymin, float ymax);

    void start(const char *title);
    void cleanup(bool destroyObjects=false);
};

#endif

#ifndef UNIVERSE_APPLICATION_H_
#define UNIVERSE_APPLICATION_H_

#include <raylib.h>

#include "solar.hpp"

class Application {
    public:
    Universe& universe;
    float width_scale, height_scale, time_scale;
    int window_width, window_height;
    double time_elapsed;

    Application(Universe& universe, float width_scale, float height_scale, float time_scale, int window_width = 600, int window_height = 600);
    void draw();
    void logic();
    void mainloop();
};

#endif
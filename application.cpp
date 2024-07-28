#include <stdio.h>
#include <math.h>

#include <raylib.h>

#include "application.hpp"

Application::Application(Universe& universe, float width_scale, float height_scale,
float time_scale, int window_width, int window_height)
    : universe { universe }, width_scale {width_scale},
    height_scale {height_scale}, time_scale {time_scale},
    time_elapsed {0}, window_width {window_width},
    window_height {window_height}
{
    InitWindow(window_width, window_height, "Solar Simulator");
    SetTargetFPS(60);
}

void Application::mainloop() {
    BeginDrawing();

    ClearBackground(BLACK);

    EndDrawing();

    while (!WindowShouldClose()) {
        logic();
        draw();
    }
}

void Application::logic() {
    double new_time_elapsed = GetTime();
    double delta_time = new_time_elapsed - time_elapsed;
    time_elapsed = new_time_elapsed;

    universe.elapse(delta_time * time_scale);
}

void Application::draw() {
    BeginDrawing();

    ClearBackground(BLACK);

    for (int i = 0; i < universe.planets.size(); i++) {
        // printf("hello\n");
        const Planet& planet = universe.planets[i];
        int window_x = round(
            planet.position(0) * width_scale + window_width / 2
        );
        int window_y = round(
            - planet.position(1) * height_scale + window_height / 2
        );
        DrawCircle(window_x, window_y, 1, RAYWHITE);
    }

    EndDrawing();
}
#include<stdio.h>

#include "solar.hpp"
#include "application.hpp"

int main() {
    Universe universe;
    universe.planets = {
        Planet { // sun
            .position = {0, 0},
            .velocity = {0, 0},
            .mass = 1.989e30,
        },
        Planet { // earth
            .position = {1.496e11, 0},
            .velocity = {0, 2.978e4},
            .mass = 5.97e24,
        }
    };

    Application app(universe, 2e-9, 2e-9, 10 * 86400, 800, 800);

    app.mainloop();

    return 0;
}


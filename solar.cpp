#include <math.h>
#include <stdio.h>

#include <vector>

#include <eigen3/Eigen/Dense>

#include "solar.hpp"

using namespace std;

void Planet::updatePosition(const float time) {
    this->position = this->position + this->velocity * time;
}

void Planet::updateVelocity(const float time, const Eigen::Vector2f acceleration) {
    this->velocity = this->velocity + acceleration * time;
}

Eigen::Vector2f Planet::calculateForceOn(const Planet& other) {
    float magnitude = other.mass * ((G * this->mass)  / pow((this->position - other.position).norm(), 2));
    Eigen::Vector2f direction = (this->position - other.position) / (this->position - other.position).norm();

    return magnitude * direction;
}

Universe::Universe() {

}

void Universe::elapse(const float time) {
    // Elapses 'time' seconds in the universe.
    // We calculate this with the following method:
    // First the planet moves along its current trajectory for
    // half the time. Then we calculate the acceleration that would
    // apply with the planet in that midway position. Then we let
    // the planet continue with that velocity. Only then do we update
    // the velocity. This is slightly more robust than calculating the acceleration
    // at the start.
    vector<Eigen::Vector2f> accelerations(planets.size());

    // for (int i =0; i < this->planets.size(); i++) {
    //     planets[i].updatePosition(time / 2);
    // }

    for (int i = 0; i < this->planets.size(); i++) {
        accelerations[i] = {0, 0};
        for (int j = 0; j < this->planets.size(); j++) {
            if (i == j) {
                continue;
            }
            accelerations[i] += planets[j].calculateForceOn(planets[i]) / planets[i].mass;
        }
    }

    for (int i = 0; i < this->planets.size(); i++) {
        planets[i].updateVelocity(time, accelerations[i]);
        planets[i].updatePosition(time);
    }
}
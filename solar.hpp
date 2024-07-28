#ifndef UNIVERSE_SOLAR_H_
#define UNIVERSE_SOLAR_H_

#include <vector>

#include <eigen3/Eigen/Dense>

using namespace std;

// const float G = 1;
const float G = 6.674e-11;

class Planet {
    public:
    Eigen::Vector2f position;
    Eigen::Vector2f velocity;
    float mass;

    void updatePosition(const float time);
    void updateVelocity(const float time, const Eigen::Vector2f acceleration);
    Eigen::Vector2f calculateForceOn(const Planet& other);
};

class Universe {
    public:
    vector<Planet> planets;
    float time_elapsed;

    Universe();

    void calculateAccelerations() const;
    void elapse(const float time);
};

#endif
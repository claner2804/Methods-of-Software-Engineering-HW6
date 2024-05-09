
#include "motor.h"
#include "robotException.h"
#include <iostream>

void motor::setSpeed(int speed) {
    if (speed < 0 || speed > 10) {
        throw InvalidSpeedException("Speed out of range!");
    }
    this->speed = speed;
}

int motor::getSpeed() {
    return speed;
}

void motor::emergencyBrake() {
    speed = 0;
}




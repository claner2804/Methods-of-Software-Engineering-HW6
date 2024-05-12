
#include "motor.h"
#include "robotException.h"
#include <iostream>

void motor::setSpeed(int speed) {
     //wenn speed < 0 oder speed > 10, dann InvalidSpeedException werfen
        if (speed < 0 || speed > 10) {
            throw InvalidSpeedException("motor::setSpeed Speed out of range!");
        }
        this->speed = speed;
}

int motor::getSpeed() {
    return speed;
}

void motor::emergencyBrake() {
    speed = 0;
}




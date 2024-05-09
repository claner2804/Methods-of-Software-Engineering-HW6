//
// Created by Claudia Steiner on 09.05.24.
//

#include "sensor.h"
#include "robotException.h"

int sensor::checkSensor() {
    //zufällige zahl zwischen 0 und 100
    int state = rand() % 101;
    if (state == 100) {
        throw CriticalDangerException("sensor.cpp Critical Danger Exception");
    }
    return state;
}

//getter
bool sensor::getErrorState() {
    if (errorState) {
        return true;
    }
    return false;
}

//reset
void sensor::reset() {
    errorState = false;
    state = 0;
}

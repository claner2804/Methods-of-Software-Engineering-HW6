//
// Created by Claudia Steiner on 09.05.24.
//

#include "ultrasonicSensor.h"
#include "robotException.h"


int ultrasonicSensor::checkSensor() {
    // 20% chance auf InternalErrorException
    if (rand() % 10 < 2) {
        throw InternalErrorException("ultrasonicSenor::checkSensor Internal Error Exception");
    }
    // 10% chance auf CriticalDangerException
    if (rand() % 10 == 0) {
        throw CriticalDangerException("ultrasonicSenor::checkSensor Critical Danger Exception");
    }
    // kann Gefahrenlevels zwischen 0 und 60 melden
    return rand() % 61;
}



void ultrasonicSensor::reset() {
    // 60% Chance auf erfolgreiches Reset
    if (rand() % 10 < 6) {
    errorState = false;
    } else {
        errorState = true;
        //wenn reset nicht erfolgreich, dann InternalErrorException werfen
        throw InternalErrorException("ultrasonicSensor::reset Internal Error Exception");

    }
}
























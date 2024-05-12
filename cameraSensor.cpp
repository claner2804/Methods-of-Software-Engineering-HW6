//
// Created by Claudia Steiner on 09.05.24.
//

#include "cameraSensor.h"


#include "ultrasonicSensor.h"
#include "robotException.h"


int cameraSensor::checkSensor() {
    // 20% chance auf InternalErrorException
    if (rand() % 10 < 2) {
        throw InternalErrorException("ultrasonicSenor::checkSensor Internal Error Exception");
    }
    // 25% chance auf CriticalDangerException
    if (rand() % 10 < 3) {
        throw CriticalDangerException("ultrasonicSenor::checkSensor Critical Danger Exception");
    }
    // kann Gefahrenlevels zwischen 0 und 100 melden
    return rand() % 101;
}



void cameraSensor::reset() {
    // 40% Chance auf erfolgreiches Reset
    if (rand() % 10 < 4) {
        errorState = false;
    } else {
        errorState = true;
        //wenn reset nicht erfolgreich, dann InternalErrorException werfen
        throw InternalErrorException("cameraSensor::reset Internal Error Exception");
    }
}


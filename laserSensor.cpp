//
// Created by Claudia Steiner on 09.05.24.
//

#include "laserSensor.h"


#include "ultrasonicSensor.h"
#include "robotException.h"


int laserSensor::checkSensor() {
    // 10% chance auf InternalErrorException
    if (rand() % 10 == 0){
        throw InternalErrorException("ultrasonicSenor::checkSensor Internal Error Exception");
    }
    // 20% chance auf CriticalDangerException
    if (rand() % 10 < 2) {
        throw CriticalDangerException("ultrasonicSenor::checkSensor Critical Danger Exception");
    }
    // kann Gefahrenlevels zwischen 0 und 80 melden
    return rand() % 81;
}



void laserSensor::reset() {
    // 50% Chance auf erfolgreiches Reset
    if (rand() % 10 < 5) {
        errorState = false;
    } else {
        errorState = true;
        //wenn reset nicht erfolgreich, dann InternalErrorException werfen
        throw InternalErrorException("ultrasonicSensor::reset Internal Error Exception");
    }
}

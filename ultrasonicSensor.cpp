//
// Created by Claudia Steiner on 09.05.24.
//

#include "ultrasonicSensor.h"

//wenn checkSensor eine Zahl zwischen 0 und 60 zruückgibt, dann error = true setzen
void ultrasonicSensor::setErrorState() {
    if (checkSensor() <= 60) {
        errorState = true;
    }
}














ultrasonicSensor::ultrasonicSensor() {
    std::cout << "Konstruktor UltrasonicSensor" << std::endl;
}


ultrasonicSensor::~ultrasonicSensor() {
    std::cout << "Destruktor UltrasonicSensor" << std::endl;
}








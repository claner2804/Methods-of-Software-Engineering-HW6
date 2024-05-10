//
// Created by Claudia Steiner on 09.05.24.
//

#ifndef HW6_ULTRASONICSENSOR_H
#define HW6_ULTRASONICSENSOR_H

#include "sensor.h"



class ultrasonicSensor : public sensor{

public:

    int checkSensor() override;

    void reset() override;

    std::string getName() override {
        return "UltrasonicSensor";
    }





 ultrasonicSensor() {
    }


~ultrasonicSensor() {
     std::cout << "Destruktor UltrasonicSensor" << std::endl;
    }



};


#endif //HW6_ULTRASONICSENSOR_H

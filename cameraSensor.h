//
// Created by Claudia Steiner on 09.05.24.
//

#ifndef HW6_CAMERASENSOR_H
#define HW6_CAMERASENSOR_H

#include "sensor.h"



class cameraSensor : public sensor{

public:

    int checkSensor() override;

    void reset() override;






    cameraSensor() {
        std::cout << "Konstruktor UltrasonicSensor" << std::endl;
    }


    ~cameraSensor() {
        std::cout << "Destruktor UltrasonicSensor" << std::endl;
    }



};



#endif //HW6_CAMERASENSOR_H

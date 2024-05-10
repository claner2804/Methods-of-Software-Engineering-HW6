//
// Created by Claudia Steiner on 09.05.24.
//

#ifndef HW6_LASERSENSOR_H
#define HW6_LASERSENSOR_H

#include "sensor.h"


class laserSensor : public sensor{

public:

    int checkSensor() override;

    void reset() override;






    laserSensor() {
        std::cout << "Konstruktor UltrasonicSensor" << std::endl;
    }


    ~laserSensor() {
        std::cout << "Destruktor UltrasonicSensor" << std::endl;
    }



};


#endif //HW6_LASERSENSOR_H

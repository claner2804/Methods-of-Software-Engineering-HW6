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

    std::string getName() override {
        return "LaserSensor";
    }






    laserSensor() {
    }


    ~laserSensor() {
        std::cout << "Destruktor laserSensor" << std::endl;
    }



};


#endif //HW6_LASERSENSOR_H

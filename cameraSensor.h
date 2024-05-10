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


    std::string getName() override {
        return "CameraSensor";
    }




    cameraSensor() {
    }


    ~cameraSensor() {
        std::cout << "Destruktor cameraSensor" << std::endl;
    }



};



#endif //HW6_CAMERASENSOR_H

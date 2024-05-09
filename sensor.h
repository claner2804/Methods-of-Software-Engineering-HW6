//
// Created by Claudia Steiner on 09.05.24.
//

#ifndef HW6_SENSOR_H
#define HW6_SENSOR_H

#include <stdexcept>
#include <iostream>


class sensor {
protected:
    bool errorState = false;
    int state = 0;

public:
    virtual int checkSensor();

    bool getErrorState();

    void reset();



};


#endif //HW6_SENSOR_H

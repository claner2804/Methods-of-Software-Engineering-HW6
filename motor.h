//
// Created by Claudia Steiner on 09.05.24.
//

#ifndef HW6_MOTOR_H
#define HW6_MOTOR_H


class motor {
private:
    int speed = 0;

public:
    void setSpeed(int speed);
    int getSpeed();
    void emergencyBrake();

};


#endif //HW6_MOTOR_H

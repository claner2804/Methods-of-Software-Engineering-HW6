#include <iostream>
#include <memory>
#include <map>
#include "robotException.h"
#include "motor.h"
#include "robot.h"
#include "sensor.h"
#include "ultrasonicSensor.h"
#include "cameraSensor.h"
#include "laserSensor.h"


int main() {

    // Create robot
    robot robot;

    // Create sensors
    robot.addSensor(std::make_shared<ultrasonicSensor>());
    robot.addSensor(std::make_shared<cameraSensor>());
    robot.addSensor(std::make_shared<laserSensor>());


    robot.eventLoop();

}
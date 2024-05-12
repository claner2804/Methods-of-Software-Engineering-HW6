cmake_minimum_required(VERSION 3.27)
project(HW6)

set(CMAKE_CXX_STANDARD 17)

add_executable(HW6 main.cpp
        motor.h
        motor.cpp
        robot.h
        robot.cpp
        sensor.h
        sensor.cpp
        ultrasonicSensor.h
        ultrasonicSensor.cpp
        laserSensor.h
        laserSensor.cpp
        cameraSensor.h
        cameraSensor.cpp
        robotException.h)

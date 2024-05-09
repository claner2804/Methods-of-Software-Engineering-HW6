//
// Created by Claudia Steiner on 09.05.24.
//

#ifndef HW6_ROBOT_H
#define HW6_ROBOT_H

#include "sensor.h"
#include <map>
#include <memory>
#include "motor.h"

/*
 * Die Klasse Robot repräsentiert den Roboter selber und implementiert die zentrale Steuerung des Roboters.
 * Sie verwaltet die Motoren und die Sensoren, d.h. sie übernimmt für diese die Object Ownership.
 * Es gibt genau einen Motor, diesen können Sie statisch zur Klasse hinzufügen (als Objektvariable).
 * Die Sensorkonfiguration hingegen ist ständigen Änderungen unterworfen, daher benötigen Sie
 * für deren Verwaltung einen dynamische Datencontainer.
 */

class robot {

private:
    //map für die dynamische Verwaltung der Sensoren
    std::map<int, std::shared_ptr<sensor>> sensors;

    //statischer motor
    static motor motor;

public:
    int addSensor(sensor* sensor);

    sensor* getSensor(int id);

    void deleteSensor(int id);

    void eventLoop();


};


#endif //HW6_ROBOT_H

//
// Created by Claudia Steiner on 09.05.24.
//

#include "robot.h"
#include <map>
#include "sensor.h"
#include <memory>

/*
 * Die Klasse Robot repräsentiert den Roboter selber und implementiert die zentrale Steuerung des Roboters.
 * Sie verwaltet die Motoren und die Sensoren, d.h. sie übernimmt für diese die Object Ownership.
 * Es gibt genau einen Motor, diesen können Sie statisch zur Klasse hinzufügen (als Objektvariable).
 * Die Sensorkonfiguration hingegen ist ständigen Änderungen unterworfen, daher benötigen Sie
 * für deren Verwaltung einen dynamische Datencontainer.
 */


int robot::addSensor(sensor* newSensor) {
    // einen neuen Sensor erstellen und in shared_ptr umwandeln
    std::shared_ptr<sensor> sensorPtr = std::make_shared<sensor>(*newSensor);

    // Sensor in map einfügen
    sensors.insert(std::pair<int, std::shared_ptr<sensor>>(sensors.size(), sensorPtr));

    // ID zurückgeben
    int id = sensors.size() - 1;
    return id;
}



sensor *robot::getSensor(int id) {
    // Get sensor with id
    return sensors.at(id).get();
}



void robot::deleteSensor(int id) {
    // Delete sensor with id
    sensors.erase(id);

    //alle ressourcen freigeben
    sensors[id].reset();
}



void robot::eventLoop() {
    //TODO: Implementieren Sie die Methode eventLoop
}



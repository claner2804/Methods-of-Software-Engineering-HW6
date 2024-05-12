//
// Created by Claudia Steiner on 09.05.24.
//

#include "robot.h"
#include <map>
#include "sensor.h"
#include <memory>
#include "motor.h"
#include <thread>
#include <algorithm>
#include "robotException.h"
#include "ultrasonicSensor.h"
#include "cameraSensor.h"
#include "laserSensor.h"

/*
 * Die Klasse Robot repräsentiert den Roboter selber und implementiert die zentrale Steuerung des Roboters.
 * Sie verwaltet die Motoren und die Sensoren, d.h. sie übernimmt für diese die Object Ownership.
 * Es gibt genau einen Motor, diesen können Sie statisch zur Klasse hinzufügen (als Objektvariable).
 * Die Sensorkonfiguration hingegen ist ständigen Änderungen unterworfen, daher benötigen Sie
 * für deren Verwaltung einen dynamische Datencontainer.
 */


//statischer motor erstellen
motor robot::motor;



//konstruktor
robot::robot() {
    std::cout << "Roboter starten initialisiert... !" << std::endl;
    std::cout << "Motor gestartet!" << std::endl;
    addSensor(std::make_shared<ultrasonicSensor>());
    addSensor(std::make_shared<cameraSensor>());
    addSensor(std::make_shared<laserSensor>());
    std::cout << "Roboter erfolgreich gestartet!" << std::endl;

}

int robot::addSensor(const std::shared_ptr<sensor>& sensor) {
    // Füge Sensor hinzu
    sensors.insert(std::make_pair(sensors.size(), sensor));

    //sensor mit name ausgeben
    std::cout << "Sensor " << sensor->getName() << " zum Roboter hinzugefügt!" << std::endl;

    // Gebe die ID des Sensors zurück
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

    std::cout << "Sensor gelöscht!" << std::endl;
}


/*
Ablauf Event-Loop
Die Event-Loop fragt ständig in einer Endlosschleife den Status der Sensoren ab.
Die Rückgabewerte der Sensoren ist eine Zahl zwischen 0 und 100,
je nach Schwere der entdeckten Gefahr (0 bedeutet keine Gefahr und 100 bedeutet sehr große Gefahr).
Nachdem alle Sensoren abgefragt wurden, wird der höchste gemeldete Gefahrenlevel
 verwendet um die Geschwindigkeit des Motors zu setzen.
 Zum Beispiel, bei keiner gemeldeten Gefahr kann der Roboter
 sich mit voller Geschwindigkeit bewegen und beim höchsten Gefahrenlevel
 nur mit niedrigster Geschwindkeit.

Wenn ein Sensor eine CriticalDangerException wirft, dann soll sofort (d.h. das Abfragen der weiteren Sensoren wird an dieser Stelle unterbrochen) ein Notstopp der Motoren eingeleitet werden.

Nach 3 Iterationen der Event-Loop soll dann wieder zum Normalzustand zurückgekehrt werden.


Wenn einer der Sensoren eine InternalErrorException wirft, dann soll aus Sicherheitsgründen auf die niedrigste Geschwindigkeit geschalten werden. Die niedrigste Geschwindigkeit soll so lange aufrechterhalten werden, bis der Sensor erfolgreich mit reset() zurückgesetzt werden konnte (reset() wird für jeden fehlerhaften Sensor nur einmal pro Iteration ausgeführt). Bei Geschwindigkeitsreduktion augrund interner Sensorfehler kann es aber immer noch zur Notabschaltung aufgrund kritischer Gefahr kommen!
Lassen Sie aus praktischen Gründen nach jeder Iteration die Event-Loop eine Sekunde schlafen (mittels sleep()). Verwenden Sie ausserdem aus praktischen Gründen (um die Korrektur der Klausur zu erleichtern) keine echte Endlosschleife. Stattdessen soll nach 30 Iterationen die "Endlosschleife" beendet werden.
 */


void robot::eventLoop() {

    std::srand(std::time(nullptr));

    std::cout << "--------------------------------" << std::endl;

    std::cout << "Event-Loop beginnt!" << std::endl;

    // Zähler für Notbremsen
    int emergencyBrakeCounter = 0;

    // Durchlaufe die Event-Loop 30 Mal
    for (int i = 1; i <= 30; i++) {

        std::cout << "--------------------------------" << std::endl;

        std::cout << "Iteration " << i << std::endl;

        // Initialisiere den maximalen Gefahrenlevel auf 0
        int maxDangerLevel = 0;

        // Flag für Notbremse
        bool emergencyBrake = false;

        // Durchlaufe alle Sensoren
        for (auto &sensor : sensors) {
            try {

                std::cout << " ---> Sensor " << sensor.second->getName() << " wird geprüft!" << std::endl;

                // Prüfe den Sensor und speichere den Gefahrenlevel
                int dangerLevel = sensor.second->checkSensor();

                // Ausgabe des Gefahrenlevels
                std::cout << "Gefahrenlevel: " << dangerLevel << std::endl;

                // Aktualisiere den maximalen Gefahrenlevel
                maxDangerLevel = std::max(maxDangerLevel, dangerLevel);
            } catch (const CriticalDangerException& e) {
                //ausgabe der Fehlermeldung
                std::cout << "Ein Kritischer Fehler ist passiert! NOTBREMSE!" << std::endl;
                // Bei kritischer Gefahr,führe eine Notbremse durch und setze das Notbremse-Flag
                motor.emergencyBrake();
                emergencyBrake = true;
                //aktuelle geschwindigkeit ausgeben:
                std::cout << "Aktuelle Geschwindigkeit: " << motor.getSpeed() << std::endl;

                // Breche die Sensorprüfung ab
                break;
            } catch (const InternalErrorException& e) {
                //ausgabe der Fehlermeldung
                std::cout << "Ein Interner Fehler ist passiert! Geschwindigkeit wird auf Minimum gesetzt!" << std::endl;
                // Bei internem Sensorfehler, setze die Geschwindigkeit auf das Minimum und setze den Sensor zurück
                motor.setSpeed(1);

                //aktuelle geschwindigkeit ausgeben:
                std::cout << "Aktuelle Geschwindigkeit: " << motor.getSpeed() << std::endl;

                std::cout << "Reset des Sensors..." << std::endl;

                // Versuche den Sensor zurückzusetzen
                try {
                    sensor.second->reset();
                } catch (const InternalErrorException& e) {
                    // Bei einem weiteren internen Fehler, führe eine Notbremse durch und setze das Notbremse-Flag
                    motor.emergencyBrake();
                    emergencyBrake = true;
                    //aktuelle geschwindigkeit ausgeben:
                    std::cout << "Aktuelle Geschwindigkeit nach Sensor reset: " << motor.getSpeed() << std::endl;

                    // Breche die Sensorprüfung ab
                    break;
                }
            }
        }

        // Wenn eine Notbremse durchgeführt wurde
        if (emergencyBrake) {
            // Erhöhe den Notbremsen-Zähler
            emergencyBrakeCounter++;

            // Wenn 3 Notbremsen durchgeführt wurden
            if (emergencyBrakeCounter == 3) {
                std::cout << "3 Notbremsen wurden durchgeführt! Setze zurück!" << std::endl;
                // Setze alle Sensoren zurück
                for (auto &sensor : sensors) {
                    try {
                        sensor.second->reset();
                    } catch (const InternalErrorException& e) {
                        // Bei einem weiteren internen Fehler, führe eine Notbremse durch und setze das Notbremse-Flag
                        motor.emergencyBrake();
                        //aktuelle geschwindigkeit ausgeben:
                        std::cout << "Aktuelle Geschwindigkeit von " << sensor.second->getName() << " nach reset: " << motor.getSpeed() << std::endl;
                    }
                }

                // Setze den Notbremsen-Zähler zurück
                emergencyBrakeCounter = 0;
            }
        } else {

            motor.setSpeed(10);

            // aktuelle geschwindigkeit ausgeben:
            std::cout << "Aktuelle Geschwindigkeit: " << motor.getSpeed() << std::endl;

        }

        // Lasse die Event-Loop nach jeder Iteration eine Sekunde schlafen
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
}

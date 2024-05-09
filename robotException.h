//
// Created by Claudia Steiner on 09.05.24.
//

#ifndef HW6_ROBOTEXCEPTION_H
#define HW6_ROBOTEXCEPTION_H

#include <stdexcept>

// Basisklasse für alle Exceptions
// erbt von std::runtime_error
class RobotException : public std::runtime_error {
public:
    //fehlermeldung wird dem Konstruktor übergeben
    explicit RobotException(const std::string &message) : std::runtime_error(message) {
    }
};

// Exception für ungueltige Geschwindigkeiten
class InvalidSpeedException : public RobotException {
public:
    explicit InvalidSpeedException(const std::string &message) : RobotException(message) {}
};


//criticalDangerException
class CriticalDangerException : public RobotException {
public:
    explicit CriticalDangerException(const std::string &message) : RobotException(message) {}

};


//internalErrorException
class InternalErrorException : public RobotException {
public:
    explicit InternalErrorException(const std::string &message) : RobotException(message) {}
};


#endif //HW6_ROBOTEXCEPTION_H

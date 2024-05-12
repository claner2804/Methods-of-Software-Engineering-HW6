CXXFLAGS = -std=c++11

factory: main.o cameraSensor.o laserSensor.o motor.o robot.o sensor.o ultrasonicSensor.o
	g++ $(CXXFLAGS) -o factory main.o cameraSensor.o laserSensor.o motor.o robot.o sensor.o ultrasonicSensor.o

main.o: main.cpp
	g++ $(CXXFLAGS) -c main.cpp

cameraSensor.o: cameraSensor.cpp cameraSensor.h
	g++ $(CXXFLAGS) -c cameraSensor.cpp

laserSensor.o: laserSensor.cpp laserSensor.h
	g++ $(CXXFLAGS) -c laserSensor.cpp

motor.o: motor.cpp motor.h
	g++ $(CXXFLAGS) -c motor.cpp

robot.o: robot.cpp robot.h
	g++ $(CXXFLAGS) -c robot.cpp

sensor.o: sensor.cpp sensor.h
	g++ $(CXXFLAGS) -c sensor.cpp

ultrasonicSensor.o: ultrasonicSensor.cpp ultrasonicSensor.h
	g++ $(CXXFLAGS) -c ultrasonicSensor.cpp

clean:
	rm -f *.o factory
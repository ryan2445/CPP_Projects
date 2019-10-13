//Ryan Hoffman - CS202 - Project5
#include <iostream>
#include <fstream>
#include <cstring>
#include "Car.h"
using namespace std;

//defautl constructor
Car::Car(){
	 m_throttle=0;
	 cout << "Car#" << m_vin << ": Default-ctor" << endl;
}

//parameterized constructor
Car::Car(char * plates, int vin, float * lla){
	m_throttle=0;
	setPlates(plates);
	setLla(lla);
	cout << "Car#" << m_vin << ": Parametrized-ctor" << endl;
}

//copy constructor
Car::Car(Car & car){
	setPlates(car.m_plates);
	setLla(car.m_lla);
	cout << "Car#" << m_vin << ": Copy-ctor" << endl;
}

//car destructor
Car::~Car(){
	cout << "Car#" << m_vin << ": Dtor" << endl;
}

//assigns new car values to parameter car values
Car & Car::operator=(Car & car){
	setLla(car.m_lla);
	setPlates(car.m_plates);
	cout << "Car#" << m_vin << ": Assignment" << endl;
	return *this;
}

//returns m_plates
char * Car::getPlates(){
	return m_plates;
}

//returns m_throttle
int Car::getThrottle(){
	return m_throttle;
}

//sets m_plates to parameter value
void Car::setPlates(char * plates){
	strcpy(m_plates, plates);
}

//sets m_throttle to parameter value
void Car::setThrottle(int throttle){
	m_throttle=throttle;
}

//sets throttle to parameter value
void Car::drive(int throttle){
	setThrottle(throttle);
}

//calls drive function with value 75
//sets lla to parameter value
void Car::move(float * lla){
	cout << "Car#" << m_vin << ": DRIVE to destination, with throttle @ 75 " << endl;
	drive(75);
	setLla(lla);
}

//prints vehicle data
std::ostream &operator<<(std::ostream &os, const Car &car) {
    std::cout << "Vehicle #" << car.m_vin << " Plates: " << car.m_plates << ", Throttle: " << car.m_throttle << " @ [" << car.m_lla[0] << ", " << car.m_lla[1] << ", " << car.m_lla[2] << "]" << std::endl;
    return os;
}


























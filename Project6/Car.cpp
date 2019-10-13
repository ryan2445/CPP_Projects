//Ryan Hoffman - CS202 - Project5
#include <iostream>
#include <fstream>
#include <cstring>
#include "Car.h"
using namespace std;

//defautl constructor
Car::Car(){
	 m_throttle=0;
	 cout << "Car: Default-ctor" << endl;
}

//parameterized constructor
Car::Car(float * lla){
	m_throttle=0;
	SetLLA(lla);
	cout << "Car: Parametrized-ctor" << endl;
}

//copy constructor
Car::Car(Car & car){
	SetLLA(car.m_lla);
	cout << "Car: Copy-ctor" << endl;
}

//car destructor
Car::~Car(){
	cout << "Car: Dtor" << endl;
}

//assigns new car values to parameter car values
Car & Car::operator=(Car & car){
	SetLLA(car.m_lla);
	cout << "Car: Assignment" << endl;
	return *this;
}

//returns m_throttle
int Car::getThrottle(){
	return m_throttle;
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
void Car::Move(float * lla){
	cout << "Car: DRIVE to destination, with throttle @ 75 " << endl;
	drive(75);
	SetLLA(lla);
}

void Car::serialize(std::ostream & os){
	os << "Car: Throttle: " << m_throttle << " @ [" << m_lla[0] << ", " << m_lla[1] << ", " << m_lla[2] << "]";	
}


























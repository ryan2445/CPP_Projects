//Ryan Hoffman - CS202 - Project5
#include <iostream>
#include <fstream>
#include "Vehicle.h"
using namespace std;

//default constructor
Vehicle::Vehicle(){
	cout << "Vehicle: Default-ctor" << endl;
}

//parameterized constructor
Vehicle::Vehicle(float * lla){
	cout << "Vehicle: Parameterized-ctor" << endl;
	SetLLA(lla);
}

//copy constructor
Vehicle::Vehicle(Vehicle & vehicle){
	cout << "Vehicle: Copy-ctor" << endl;
	SetLLA(vehicle.m_lla);
}

//vehicle destructor
Vehicle::~Vehicle(){
	cout << "Vehicle: Dtor" << endl;
}

//assigns vehicle to parameter value
Vehicle & Vehicle::operator=(Vehicle &vehicle){
	cout << "Vehicle: Assignment" << endl;
	SetLLA(vehicle.m_lla);
	return *this;
}

//returns m_lla
float * Vehicle::getLla(){
	return m_lla;
}

//sets individual lla values based on pointer parameter
void Vehicle::SetLLA(float * lla){
	for(int i=0;i<3;i++){
		m_lla[i]=lla[i];
	}
}

//sets individual lla values based on individual parameters
void Vehicle::SetLLA(const int lat, const int lng, const int alt){
    m_lla[0] = lat;
    m_lla[1] = lng;
    m_lla[2] = alt;
}

//
void Vehicle::Move(float *lla){
}

void Vehicle::serialize(std::ostream & os){
	os << "Vehicle @ [" << m_lla[0] << ", " << m_lla[1] << ", " << m_lla[2] << "]";
}

//prints vehicle data
std::ostream & operator<<(std::ostream & os, Vehicle & vehicle){
    vehicle.serialize(os);
    return os;
}































//Ryan Hoffman - CS202 - Project5
#include <iostream>
#include <fstream>
#include "Vehicle.h"
using namespace std;

//initializes static variable to 0
int Vehicle::s_idgen=0;

//default constructor
Vehicle::Vehicle() : m_vin(s_idgen++){
	cout << "Vehicle #" << m_vin << ": Default-ctor" << endl;
}

//parameterized constructor
Vehicle::Vehicle(int vin, float * lla) : m_vin(s_idgen++){
	cout << "Vehicle #" << m_vin << ": Parameterized-ctor" << endl;
	setLla(lla);
}

//copy constructor
Vehicle::Vehicle(Vehicle & vehicle) : m_vin(s_idgen++){
	cout << "Vehicle #" << m_vin << ": Copy-ctor" << endl;
	setLla(vehicle.m_lla);
}

//vehicle destructor
Vehicle::~Vehicle(){
	cout << "Vehicle #" << m_vin << ": Dtor" << endl;
}

//assigns vehicle to parameter value
Vehicle & Vehicle::operator=(Vehicle &vehicle){
	cout << "Vehicle #" << m_vin << ": Assignment" << endl;
	m_vin=s_idgen++;
	setLla(vehicle.m_lla);
	return *this;
}

//returns m_vin
int Vehicle::getVin(){
	return m_vin;
}

//returns m_lla
float * Vehicle::getLla(){
	return m_lla;
}

//returns s_idgen
int Vehicle::getIdgen(){
	return Vehicle::s_idgen;
}

//sets individual lla values based on pointer parameter
void Vehicle::setLla(float * lla){
	for(int i=0;i<3;i++){
		m_lla[i]=lla[i];
	}
}

//sets individual lla values based on individual parameters
void Vehicle::setLla(const int lat, const int lng, const int alt){
    m_lla[0] = lat;
    m_lla[1] = lng;
    m_lla[2] = alt;
}

//passes in new lla values and prints debug message
void Vehicle::move(float *lla){
	cout << "Vehicle #" << m_vin << ": CANNOTMOVE -I DON'T KNOW HOW" << endl;
}

//prints vehicle data
std::ostream & operator << (std::ostream & os, Vehicle & vehicle){
    std::cout << "Vehicle #" << vehicle.m_vin << " @ [" << vehicle.m_lla[0] << ", " << vehicle.m_lla[1] << ", " << vehicle.m_lla[2] << "]" << std::endl;
    return os;
}































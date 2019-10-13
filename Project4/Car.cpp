//Ryan Hoffman - CS202 - Project 4
#include <iostream>
#include <fstream>
#include "Sensor.h"
#include "String.h"
#include "Car.h"
#include "Agency.h"
using namespace std;
//Default constructor
Car::Car(){
	String s;
	m_year=0;
	s.myStringCopy(m_make, "\0");
	s.myStringCopy(m_model, "\0");
	m_baseprice=0;
	m_available=0;
	Sensor m_sensors[3];
}

//Parameterized constructor
Car::Car(int year, char * make, char * model, float price, bool available, Sensor * sensorArr){
	String s;
	m_year=year;
	s.myStringCopy(m_make, make);
	s.myStringCopy(m_model, model);
	m_baseprice=price;
	m_available=available;
	for(int i=0;i<3;i++){
		m_sensors[i]=*sensorArr;
		sensorArr++;
	}
	sensorArr-=3;
}

//Copy constructor
Car::Car(Car & car){
	String s;
	car.m_year=m_year;
	s.myStringCopy(car.m_make, m_make);
	s.myStringCopy(car.m_model, m_model);
	car.m_baseprice=m_baseprice;
	car.m_available=m_available;
	for(int i=0;i<3;i++){
		car.m_sensors[i]=m_sensors[i];
	}
}

//get functions
char * Car::getMake(){
	return m_make;
}

char * Car::getModel(){
	return m_model;
}

int Car::getYear(){
	return m_year;
}

Sensor * Car::getSensors(){
	return m_sensors;
}

float Car::getBasePrice(){
	return m_baseprice;
}

float Car::getFinalPrice(){
	Sensor * sensArr2=m_sensors;
	float extraCost=0;
	for(int i=0;i<3;i++){
		extraCost+=sensArr2->getExtraCost();
		sensArr2++;
	}
	return (m_baseprice+extraCost);
}

bool Car::getAvailable(){
	return m_available;
}

char * Car::getOwner(){
	return m_owner;
}

//set functions
void Car::setMake(char * make){
	String s;
	s.myStringCopy(m_make, make);	
}

void Car::setModel(char * model){
	String s;
	s.myStringCopy(m_model, model);
}

void Car::setYear(int year){
	m_year=year;
}

void Car::setBasePrice(float baseprice){
	m_baseprice=baseprice;
}

void Car::setAvailable(bool available){
	m_available=available;
}

void Car::setOwner(char * owner){
	String s;
	s.myStringCopy(m_owner, owner);
}

void Car::updatePrice(float price){
	m_finalprice+=price;
}

//prints all data from the car object
void Car::printData(){
	Sensor * sensArr = m_sensors;
	Sensor * sensArr2 = m_sensors;
	float extraCost=0;
	for(int i=0;i<3;i++){
		extraCost+=sensArr2->getExtraCost();
		sensArr2++;
	}
	cout << m_year << " " << m_make << " " << m_model << " $" << (m_baseprice+extraCost) << " ";
	for(int i=0;i<3;i++){
		if(i==0){
			cout << "{" << sensArr->getType() << " ";
		}
		else if(i==2){
			cout << " " << sensArr->getType() << "} ";
		}
		else{
		cout << sensArr->getType();
		}
		sensArr++;
	}
	cout << "Available: " << boolalpha << m_available << " " << m_owner << endl;
}

//returns finalprice * amount of days rented
float Car::estimateCost(int days){
	return m_finalprice*days;
}

//+ operator oberload to add a sensor to the car object
Car & Car::operator+(Sensor & sensor){
	String s;
	Sensor * ptr=m_sensors;
	if(s.myStringCompare(sensor.getType(), "none")!=0){
		//checks count of specific sensor
		if(ptr->getGps_cnt()==1){
			for(int i=0;i<3;i++){
				//checks if sensor slot is already filled
				if(s.myStringCompare(ptr->getType(), "none")!=0){
					ptr++;
				}
			}
			*ptr=sensor;
			ptr->resetGps_cnt();
		}
		else if(ptr->getCamera_cnt()==1){
			for(int i=0;i<3;i++){
				if(s.myStringCompare(ptr->getType(), "none")!=0){
					ptr++;
				}
			}
			*ptr=sensor;
			ptr->resetCamera_cnt();
		}
		else if(ptr->getLidar_cnt()==1){
			for(int i=0;i<3;i++){
				if(s.myStringCompare(ptr->getType(), "none")!=0){
					ptr++;
				}
			}
			*ptr=sensor;
			ptr->resetLidar_cnt();
		}
		else if(ptr->getRadar_cnt()==1){
			for(int i=0;i<3;i++){
				if(s.myStringCompare(ptr->getType(), "none")!=0){
					ptr++;
				}
			}
			*ptr=sensor;
			ptr->resetRadar_cnt();
		}
	}
	return *this;
}

//+ operator overload to add a lessee
Car & Car::operator+(char * lessee){
	String s;
	s.myStringCopy(m_owner, lessee);
	return *this;
}

//prints total amount of sensors (by type) in the array of sensors in the car object
void Car::totalSensors(){
	int totalGpsSensors=0;
	int totalCameraSensors=0;
	int totalLidarSensors=0;
	int totalRadarSensors=0;
	Sensor * ptr = m_sensors;
	cout << "Fleet GPS Sensors: " << ptr->getTotalGps() << endl;
	cout << "Fleet Camera Sensors: " << ptr->getTotalCamera() << endl;
	cout << "Fleet Lidar Sensors: " << ptr->getTotalLidar() << endl;
	cout << "Fleet Radar Sensors: " << ptr->getTotalRadar() << endl;
}





















































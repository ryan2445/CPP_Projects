//Ryan Hoffman - CS202 - Project 4
#include <iostream>
#include <fstream>
#include "Sensor.h"
#include "String.h"
#include "Car.h"
#include "Agency.h"
using namespace std;
//static variable initialization
int Sensor::gps_cnt=0;
int Sensor::camera_cnt=0;
int Sensor::lidar_cnt=0;
int Sensor::radar_cnt=0;

int Sensor::totalGps_sensors=0;
int Sensor::totalCamera_sensors=0;
int Sensor::totalLidar_sensors=0;
int Sensor::totalRadar_sensors=0;
//default constructor
Sensor::Sensor(){
	char none[256]="none";
	m_extracost=0;
	setType(none);
}
//parameterized constructor
Sensor::Sensor(char * type){
	m_extracost=0;
	setType(type);
}
//copy constructor
Sensor::Sensor(Sensor & sensor){
	setType(sensor.m_type);
}
//sets type of sensor
void Sensor::setType(char * type){
	String s;
	if(s.myStringCompare(type, "gps")==0){
		s.myStringCopy(m_type, type);
		setExtraCost(5);
		Sensor::gps_cnt++;
		Sensor::totalGps_sensors++;
	}
	else if(s.myStringCompare(type, "camera")==0){
		s.myStringCopy(m_type, type);
		setExtraCost(10);
		Sensor::camera_cnt++;
		Sensor::totalCamera_sensors++;
	}
	else if(s.myStringCompare(type, "lidar")==0){
		s.myStringCopy(m_type, type);
		setExtraCost(15);
		Sensor::lidar_cnt++;
		Sensor::totalLidar_sensors++;
	}
	else if(s.myStringCompare(type, "radar")==0){
		s.myStringCopy(m_type, type);
		setExtraCost(20);
		Sensor::radar_cnt++;
		Sensor::totalRadar_sensors++;
	}
	else if(s.myStringCompare(type, "none")==0){
		s.myStringCopy(m_type, type);
		setExtraCost(0);
	}
}
//set functions
void Sensor::setExtraCost(float extracost){
	m_extracost+=extracost;
}
//get functions
char * Sensor::getType(){
	return m_type;
}

float Sensor::getExtraCost(){
	return m_extracost;
}
//static variable reset functions
void Sensor::resetGps_cnt(){
	Sensor::gps_cnt=0;
}

void Sensor::resetCamera_cnt(){
	Sensor::camera_cnt=0;
}

void Sensor::resetLidar_cnt(){
	Sensor::lidar_cnt=0;
}

void Sensor::resetRadar_cnt(){
	Sensor::radar_cnt=0;
}
//static variable get functions
int Sensor::getGps_cnt(){
	return Sensor::gps_cnt;
}

int Sensor::getCamera_cnt(){
	return Sensor::camera_cnt;
}

int Sensor::getLidar_cnt(){
	return Sensor::lidar_cnt;
}

int Sensor::getRadar_cnt(){
	return Sensor::radar_cnt;
}

int Sensor::getTotalGps(){
	return Sensor::totalGps_sensors;
}
int Sensor::getTotalCamera(){
	return Sensor::totalCamera_sensors;
}
int Sensor::getTotalLidar(){
	return Sensor::totalLidar_sensors;
}
int Sensor::getTotalRadar(){
	return Sensor::totalRadar_sensors;
}





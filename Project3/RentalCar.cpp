//Ryan Hoffman - CS202 - Project 3 - RentalCar.cpp
#include <iostream>
#include <fstream>
#include "RentalCar.h"
#include "RentalAgency.h"
using namespace std;
char * myStringCopy(char * destination, const char * source);
char * myStringCat(char * destination, const char * source);
int myStringCompare(const char * str1, const char * str2);
size_t myStringLength(const char * str);

//DEFAULT CONSTRUCTOR
RentalCar::RentalCar(){
	m_year=0;
	myStringCopy(m_make, " ");
	myStringCopy(m_model, " ");
	m_price=0;
	m_available=0;
}

//CONSTRUCTOR WITH PARAMETERS
RentalCar::RentalCar(int year, char * make, char * model, float price, bool available){
	m_year=year;
	myStringCopy(m_make, make);
	myStringCopy(m_model, model);
	m_price=price;
	m_available=available;
}

//GET FUNCTIONS====================
int RentalCar::getYear() const{
	return m_year;
}

char * RentalCar::getMake(){
	return m_make;
}

char * RentalCar::getModel(){
	return m_model;
}

float RentalCar::getPrice() const{
	return m_price;
}

bool RentalCar::getAvailable() const{
	return m_available;
}
//==================================
//SET FUNCTIONS
void RentalCar::setYear(int year){
	m_year=year;
}

void RentalCar::setMake(char * make){
	myStringCopy(m_make, make);
}

void RentalCar::setModel(char * model){
	myStringCopy(m_model, model);
}

void RentalCar::setPrice(float price){
	m_price=price;
}

void RentalCar::setAvailable(bool available){
	m_available=available;
}
//====================================
//PRINTS CAR DATA
void RentalCar::printData() const{
	cout << m_year << " " << m_make << " " << m_model << ", $" << m_price << " per day, Available: " << boolalpha << m_available << endl;
}

//RETURNS PRICE X DAYS
float RentalCar::estimateCost(int days) const{
	return (m_price*days);
}

//COPIES SOURCE STRING TO DESTINATION STRING
char * myStringCopy(char * destination, const char * source){
	int count=0;
	for(;*source!='\0';source++){
		*destination=*source;
		destination++;
		count++;
	}
	*destination='\0';
	destination-=count;
	return destination;
}

//APPENDS SOURCE STRING TO DESTINATION STRING
char * myStringCat(char * destination, const char * source){
	int count=0;
	for(;*destination!='\0';destination++){
		count++;
	}
	for(;*source!='\0';source++){
		*destination=*source;
		destination++;
		count++;
	}
	*destination='\0';
	destination=destination-count;
	return destination;
}

//RETURNS -1 IF STR1 COMES BEFORE STR2 ALPHABETICALLY
//RETURNS 1 IF STR1 COMES AFTER STR2 ALPHABETICALLY
//RETURNS 0 IF STR1 AND STR2 ARE EQUAL ALPHABETICALLY
int myStringCompare(const char * str1, const char * str2){
	while((*str1!='\0')||(*str2!='\0')){
	char str3=*str1;
	char str4=*str2;
	if(str3>=65&&str3<=90){
		str3+=32;
	}
	if(str4>=65&&str4<=90){
		str4+=32;
	}
	if(str3>str4){
		return 1;
	}
	else if(str3<str4){
		return -1;
	}
	str1++;
	str2++;
	}
	return 0;
}

//RETURNS LENGTH OF STRING
size_t myStringLength(const char * str){
	size_t count=0;
	for(;*str!='\0';str++){
		count++;
	}
	return count;
}









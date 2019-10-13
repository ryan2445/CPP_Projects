//Ryan Hoffman - CS202 - Project 4
#include <iostream>
#include <fstream>
#include "Car.h"
#include "Agency.h"
#include "Sensor.h"
#include "String.h"
using namespace std;

//Default Constructor
Agency::Agency(){
	String s;
	s.myStringCopy(m_name, " ");
	m_zipcode=00000;
	m_inventory[5];
}

//Get Agency Name
char * Agency::getName(){
	return m_name;
}

//Get Agency Zipcode
int Agency::getZipcode(){
	return m_zipcode;
}

//Set Agency Name
void Agency::setName(char * name){
	String s;
	s.myStringCopy(m_name, name);
}

//Reads In All Data From Text File
void Agency::readAllData(){
	int year=0;
	char make[256]="";
	char model[256]="";
	float baseprice=0;
	char tempchar;
	bool available=0;
	char name[256]="";
	
	ifstream read;
	char inputFile[256]="";
	cout << "Enter input file name: ";
	cin >> inputFile;
	read.open(inputFile);
	read >> m_name;
	read >> m_zipcode;
	
	Car * ptr=m_inventory;
	String s;
	for(int i=0;i<5;i++){
		char type[256]="none";
		char typeCopy[256]="none";
		char type2[256]="none";
		char type2Copy[256]="none";
		char type3[356]="none";
		char type3Copy[256]="none";
		int count=0;
		read >> year;
		read >> make;
		read >> model;
		read >> baseprice;
		read>>type;
		int length=s.myStringLength(type);
		if(type[length-1]!='}'){
			read >> type2;
			length=s.myStringLength(type2);
			if(type2[length-1]!='}'){
				read >> type3;
			}
		}
		/////////////Checks to see if at end of sensor list for first sensor
		length=s.myStringLength(type);
		if(type[length-1]=='}'){
			for(int i=1;i<length-1;i++){
				typeCopy[count]=type[i];
				typeCopy[count+1]='\0';
				count++;
			}
		}
		else{
			for(int i=1;i<length;i++){
				typeCopy[count]=type[i];
				typeCopy[count+1]='\0';
				count++;
			}
		}
		////////////Checks to see if at end of sensor list for second sensor
		count=0;
		length=s.myStringLength(type2);
		if(type2[length-1]=='}'){
			for(int i=0;i<length-1;i++){
				type2Copy[count]=type2[i];
				type2Copy[count+1]='\0';
				count++;
			}
		}
		else{
			for(int i=0;i<length;i++){
				type2Copy[count]=type2[i];
				type2Copy[count+1]='\0';
				count++;
			}
		}
		//////////////Checks to see if at end of sensor list for third sensor
		count=0;
		length=s.myStringLength(type3);
		if(type3[length-1]=='}'){
			for(int i=0;i<length-1;i++){
				type3Copy[count]=type3[i];
				type3Copy[count+1]='\0';
				count++;
			}
		}
		////////////////
		read >> available;
		//if car is unavailable, read in and set owner name
		if(available==0){
			read >> name;
			char bracket1[9]="Owner: [";
			char bracket2[3]={']'};
			char tempOwner[256];
			s.myStringCopy(tempOwner, (s.myStringCat(bracket1, name)));
			s.myStringCopy(tempOwner, (s.myStringCat(tempOwner, bracket2)));
			ptr->setOwner(tempOwner);
		}
		//set rest of data
		ptr->setYear(year);
		ptr->setMake(make);
		ptr->setModel(model);
		ptr->setBasePrice(baseprice);
		Sensor s1(typeCopy);
		Sensor s2(type2Copy);
		Sensor s3(type3Copy);
		//OPERATOR OVERLOADS
		ptr->operator+(s1);
		ptr->operator+(s2);
		ptr->operator+(s3);
		//
		ptr->setAvailable(available);
		ptr++;
	}
	read.close();
}

//prints all data using printData() from Car class
void Agency::printAllData(){
	Car * ptr=m_inventory;
	cout << getName() << " " << getZipcode() << endl;
	for(int i=0;i<5;i++){
	ptr->printData();
	ptr++;
	}
}

//prints only cars that are available
void Agency::printAvailableCars(){
	Car * ptr=m_inventory;
	for(int i=0;i<5;i++){
		if(ptr->getAvailable()==1){
			ptr->printData();
		}
		ptr++;
	}
}

//Bracket operator overload
Car & Agency::operator[](int index){
	return m_inventory[index];
}

//Prints number of sensors (by type) in the car fleet
void Agency::printFleetSensors(){
	int totalSensors=0;
	Car * ptr=m_inventory;
	ptr->totalSensors();
}

//finds most expensive car
//asks if you want to rent it
//if yes, asks for your name
//then changes car availability to false and sets Owner name
void Agency::rentCar(){
	String s;
	char input[2];
	char name[256];
	int mostExpensiveIndex=0;
	float mostExpensive=0;
	Car * ptr=m_inventory;
	for(int i=0;i<5;i++){
		if(ptr->getFinalPrice()>mostExpensive){
			mostExpensive=ptr->getFinalPrice();
			mostExpensiveIndex=i;
		}
		ptr++;
	}
	ptr-=(5-mostExpensiveIndex);
	cout << "The most expensive car is the ";
	ptr->printData();
	cout << "Would you like to rent this car? (Y/N): ";
	cin >> input;
	if(s.myStringCompare(input, "Y")==0){
		cout << "Enter your name: ";
		cin >> name;
		char bracket1[9]="Owner: [";
		char bracket2[3]={']'};
		char tempOwner[256];
		s.myStringCopy(tempOwner, (s.myStringCat(bracket1, name)));
		s.myStringCopy(tempOwner, (s.myStringCat(tempOwner, bracket2)));
		ptr->setOwner(tempOwner);
		ptr->setAvailable(0);
	}
}

























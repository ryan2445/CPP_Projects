//Ryan Hoffman - CS202 - Project 4
#include <iostream>
#include <fstream>
#include "Sensor.h"
#include "String.h"
#include "Car.h"
#include "Agency.h"
using namespace std;

int main(){
//Agency Object
Agency agency;
int input;
	do{
		//Menu
		cout << "1) Read agency data from input file" << endl;
		cout << "2) Print agency data to terminal" << endl;
		cout << "3) Print total number of sensors in fleet(by type)" << endl;
		cout << "4) Rent most expensive car" << endl;
		cout << "5) Exit" << endl;
		cout << "Enter your option: ";
		cin >> input;
			switch(input){
			case 1:
			agency.readAllData();
			break;
			case 2:
			agency.printAllData();
			break;
			case 3:
			agency.printFleetSensors();
			break;
			case 4:
			agency.rentCar();
			break;
			case 5:
			break;
	}
	}while(input!=5);
	//End Program
	return 0;
}

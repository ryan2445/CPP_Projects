//Ryan Hoffman - CS202 - Project 3 - proj3.cpp
//*You must compile both cpp files for the program to work.* ex: g++ proj3.cpp RentalCar.cpp -o proj3
#include <iostream>
#include <fstream>
#include "RentalCar.h"
#include "RentalAgency.h"
using namespace std;
void readData(RentalAgency * ptr);
void printData(RentalAgency * ptr);
void menu3(RentalAgency * ptr);
void menu4(RentalAgency * ptr);
void menu5(RentalAgency * ptr, ofstream &write);
int main(){
	int input=0;
	RentalAgency companies[3];
	ofstream write;
	//MENU
	do{
	cout << "1) Read car data from input file" << endl;
	cout << "2) Print car data to terminal" << endl;
	cout << "3) Estimate car rental cost" << endl;
	cout << "4) Most expensive car" << endl;
	cout << "5) Write available cars to output file" << endl;
	cout << "6) Exit" << endl;
	cout << "Enter your option: ";
	cin >> input;
	switch(input){
		case 1:
		readData(companies);
		break;
		case 2:
		printData(companies);
		break;
		case 3:
		menu3(companies);
		break;
		case 4:
		menu4(companies);
		break;
		case 5:
		menu5(companies, write);
		break;
		case 6:
		cout << "*Closing program...*" << endl;
		break;
	}
	} while(input!=6);
	
	return 0;
}

//READS DATA FROM USER INPUTTED FILE
void readData(RentalAgency * ptr){
	char inputFile[256];
	int year;
	char make[256];
	char model[256];
	float price;
	bool available;
	int temp=0;
	ifstream read;
	cout << "Enter input file name: ";
	cin >> inputFile;
	read.open(inputFile);
	for(int i=0;i<3;i++){
	read >> ptr->name;
	read >> temp;
	for(int j=0;j<5;j++){
		ptr->zipcode[j]=(temp%10);
		temp/=10;
	}
	for(int k=0;k<5;k++){
		read >> year;
		ptr->inventory[k].setYear(year);
		read >> make;
		ptr->inventory[k].setMake(make);
		read >> model;
		ptr->inventory[k].setModel(model);
		read >> price;
		ptr->inventory[k].setPrice(price);
		read >> available;
		ptr->inventory[k].setAvailable(available);
	}
	ptr++;
	}
	read.close();
	cout << "*Data has been read from the input file*" << endl;
}

//PRINTS DATA STORED IN RENTALAGENCY ARRAY TO TERMINAL
void printData(RentalAgency * ptr){
	for(int i=0;i<3;i++){
		cout << "=======================================" << endl;
		cout << ptr->name << " ";
		for(int k=0;k<5;k++){
			cout << ptr->zipcode[k];
		}
		cout << endl;
		for(int j=0;j<5;j++){
			ptr->inventory[j].printData();
		}
		ptr++;
	}
	cout << "=======================================" << endl;
}

//PRINTS ESTIMATED COST TO RENT CAR BASED ON AGENCY, CAR INDEX, AND # OF DAYS
void menu3(RentalAgency * ptr){
	int index;
	int days;
	for(int i=0;i<3;i++){
		cout << i << ") " << ptr->name << endl;
		ptr++;
	}
	cout << "Enter agency index: ";
	cin >> index;
	ptr-=3;
	ptr+=index;
	for(int j=0;j<5;j++){
		cout << j << ") ";
		ptr->inventory[j].printData();
	}
	cout << "Enter car index: ";
	cin >> index;
	cout << "Enter how many days: ";
	cin >> days;
	cout << "*It costs $" << ptr->inventory[index].estimateCost(days) << " to rent that car for " << days << " days*" << endl;
}

//PRINTS THE MOST EXPENSIVE CAR TO THE TERMINAL
void menu4(RentalAgency * ptr){
	float biggest=0;
	int aIndex=0;
	int cIndex=0;
	for(int i=0;i<3;i++){
		for(int j=0;j<5;j++){
			if(ptr->inventory[j].getPrice()>biggest){
				biggest=ptr->inventory[j].getPrice();
				cIndex++;
				aIndex=i;
			}
		}
		ptr++;
		cIndex=0;
	}
	ptr-=3;
	ptr+=aIndex;
	cout << "*The most expensive car is the " << ptr->inventory[cIndex].getYear() << " " << ptr->inventory[cIndex].getMake() << " " << ptr->inventory[cIndex].getModel()
	<< ", $" << ptr->inventory[cIndex].getPrice() << " per day, Available: " << boolalpha << ptr->inventory[cIndex].getAvailable() << "*" << endl;
}

//PRINTS ALL AVAILABLE CARS TO THE OUTPUT FILE
void menu5(RentalAgency * ptr, ofstream &write){
	char outputFile[256];
	cout << "Enter an output file: ";
	cin >> outputFile;
	write.open(outputFile);
	for(int i=0;i<3;i++){
		write << ptr->name << " ";
		for(int k=0;k<5;k++){
			write << ptr->zipcode[k];
		}
		write << endl;
		for(int j=0;j<5;j++){
			if(ptr->inventory[j].getAvailable()==1){
			write << ptr->inventory[j].getYear() << " " << ptr->inventory[j].getMake() << " " << ptr->inventory[j].getModel()
			<< ", $" << ptr->inventory[j].getPrice() << " per day, Available: " << boolalpha << ptr->inventory[j].getAvailable() << endl;
			}
		}
		ptr++;
		write << endl;
	}
	cout << "*Available cars have been written to the output file*" << endl;
}



































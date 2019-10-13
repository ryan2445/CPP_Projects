//RYAN HOFFMAN - CS 202 - PROJECT 2
#include <iostream>
#include <fstream>
using namespace std;

//CAR STRUCT
struct Car{
	int year;
	char make[10];
	char model[10];
	float price;
	bool avail;
};

//FUNCTION CALLS
size_t myStringLength(const char * str);
int myStringCompare(const char * str1, const char * str2);
char * myStringCopy(char * destination, const char * source);
char * myStringCat(char * destination, const char * source);
//MENU FUNCTION CALLS
void readData(Car * ptr);
void printData(Car* ptr);
void writeData(Car* ptr);
void priceSort(Car* ptr);
void menu5(Car* ptr);
void menu6(Car* ptr);

int main(){
	int input;
	Car cars[5];
	
	//USER MENU
	do{
	cout << "1) Read car data from input file" << endl;
	cout << "2) Print car data to terminal" << endl;
	cout << "3) Print data to output file" << endl;
	cout << "4) Sort by ascending price" << endl;
	cout << "5) Rental days" << endl;
	cout << "6) Car choice" << endl;
	cout << "7) Exit" << endl;
	cout << "Enter your option: ";
	cin >> input;
	switch(input){
		case 1:
		readData(cars);
		break;
		case 2:
		printData(cars);
		break;
		case 3:
		writeData(cars);
		break;
		case 4:
		priceSort(cars);
		break;
		case 5:
		menu5(cars);
		break;
		case 6:
		menu6(cars);
		break;
		case 7:
		break;
	}
	} while(input!=7);
	
	//END PROGRAM
	return 0;
}

//RETURNS SIZE OF PROVIDED STRING
size_t myStringLength(const char * str){
	size_t count=0;
	for(;*str!='\0';str++){
		count++;
	}
	return count;
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

//COPIES SOURCE STRING TO DESTINATION STRING
char * myStringCopy(char * destination, const char * source){
	int count=0;
	for(;*destination!='\0';destination++){
		*destination=*source;
		source++;
		count++;
	}
	*destination='\0';
	destination=destination-count;
	return destination;
}

//ATTACHES SOURCE STRING TO DESTINATION STRING
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

//READS CAR DATA FROM USER INPUTTED FILE NAME
void readData(Car* ptr){
	char inputFile[100];
	ifstream read;
	cout << "Enter input file name: ";
	cin >> inputFile;
	read.open(inputFile);
	for(int i=0;i<5;i++){
		read >> (*ptr).year;
		read >> (*ptr).make;
		read >> (*ptr).model;
		read >> (*ptr).price;
		read >> (*ptr).avail;
		ptr++;
	}
	read.close();
}

//PRINTS CAR ARRAY DATA TO TERMINAL
void printData(Car* ptr){
	for(int i=0;i<5;i++){
		cout << "[" << i << "]: " << (*ptr).year << " " << (*ptr).make << " " << (*ptr).model << ", $" << (*ptr).price << " per day, Available: " << boolalpha << (*ptr).avail << endl;
		ptr++;
	}
}

//WRITES CAR ARRAY DATA TO USER INPUTTED FILE
void writeData(Car* ptr){
	char outputFile[100];
	ofstream write;
	cout << "Enter the output file name: ";
	cin >> outputFile;
	write.open(outputFile);
	for(int i=0;i<5;i++){
		write << "[" << i << "]: " << (*ptr).year << " " << (*ptr).make << " " << (*ptr).model << ", $" << (*ptr).price << " per day, Available: " << boolalpha << (*ptr).avail << endl;
		ptr++;
	}
	write.close();
}

//SORTS CARS BY PRICE
void priceSort(Car* ptr){
	Car car;
	Car* ptr2 = ptr;
	ptr2++;
	for(int i=0;i<5-1;i++){
		for(int j=0;j<5-i-1;j++){
			if((*ptr).price>(*ptr2).price){
				car=*ptr;
				*ptr=*ptr2;
				*ptr2=car;
			}
			ptr2++;
		}
		ptr++;
		ptr2=ptr;
		ptr2++;
	}
}

//ASKS HOW MANY RENTAL DAYS
//SHOWS AVAILABLE CARS W/ TOTAL PRICE
void menu5(Car* ptr){
	int days=0;
	cout << "How many days would you like to rent the car?: ";
	cin >> days;
	priceSort(ptr);
	for(int i=0;i<5;i++){
		if((*ptr).avail==1){
			cout << "[" << i << "]: " << (*ptr).year << " " << (*ptr).make << " " << (*ptr).model << ", Total Cost: $" << ((*ptr).price)*days << endl;
			ptr++;
		}
		else{
			ptr++;
		}
	}
}

//USER ENTERS CAR INDEX
//USER ENTERS HOW MANY DAYS
//IF CAR IS AVAILABLE --> CONFIRMATION MESSAGE W/ TOTAL PRICE --> CAR IS SET TO UNAVAILABLE
//IF CAR IS NOT AVAILABLE --> ERROR MESSAGE
void menu6(Car* ptr){
	Car* ptr2=ptr;
	int indexNum;
	int days;
	printData(ptr);
	cout << "Enter the index number of which car you want to rent: ";
	cin >> indexNum;
	cout << "How many days?: ";
	cin >> days;
	for(int i=0;i<indexNum;i++){
		ptr2++;
	}
	if((*ptr2).avail==0){
		cout << "This car is not available." << endl;
		ptr2=ptr;
	}
	if((*ptr2).avail==1){
		(*ptr2).avail=0;
		cout << "Your " << (*ptr2).make << " " << (*ptr2).model << " has been rented for " << days << " days for $" << ((*ptr2).price)*days << endl;
	}
}

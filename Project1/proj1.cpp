#include <iostream>
#include <fstream>
using namespace std;

//FUNCTIONS
void myStringCopy(char destination[], const char source[]);
int myStringLength(const char str[]);
int myStringCompare(const char str1[], const char str2[]);
//

int main(){
 	//DECLARATION/INITIALIZATION
	char inputName[100];
	char outputName[100];
	char outputName2[100];
	char names[10][9];
	char order[10][2] = {'0','\0','1','\0','2','\0','3','\0','4','\0','5','\0','6','\0','7','\0','8','\0','9'};
	//
	
	//USER INPUT
	cout << "Enter the input file name: ";
	cin >> inputName;
	cout << "Enter the output file name: ";
	cin >> outputName;
	cout << "Enter the second output file name: ";
	cin >> outputName2;
	//
	
	//GETTING NAMES FROM INPUT TEXT FILE
	ifstream read;
	read.open(inputName);
	for(int i=0;i<10;i++){
		read >> names[i];
	}
	//
	
	//PRINTING UNSORTED DATA
	cout << "===================" << endl <<  "Unsorted Data:" << endl;
	for(int i=0;i<10;i++){
		cout << order[i] << " " << names[i] << endl;
	}
	cout << "===================" << endl;
	//
	
	//====================================================================================
	//SORTING DATA BY LENGTH
	cout << "Sorted-by-Length Data" << endl;
	char lengthSorted[10][9]={'\0'};
	for(int i=0;i<10;i++){
		myStringCopy(lengthSorted[i], names[i]);
	}
	for(int i=0;i<10-1;i++){
		for(int j=0;j<10-i-1;j++){
			if(myStringLength(lengthSorted[j])>myStringLength(lengthSorted[j+1])){
				char temp[1][9];
				char temp2[1][2];
				myStringCopy(temp[0], lengthSorted[j]);
				myStringCopy(lengthSorted[j], lengthSorted[j+1]);
				myStringCopy(lengthSorted[j+1], temp[0]);
				
				myStringCopy(temp2[0], order[j]);
				myStringCopy(order[j], order[j+1]);
				myStringCopy(order[j+1], temp2[0]);
			}
		}
	}
	//PRINTING AND WRITING SORTED-BY-LENGTH DATA TO TERMINAL AND TEXT FILE
	ofstream write;
	write.open(outputName);
	for(int i=0;i<10;i++){
		cout << order[i] << " " << lengthSorted[i] << endl;
		write << order [i] << " " << lengthSorted[i] << endl;
	}
	cout << "===================" << endl;
	//====================================================================================
	
	//====================================================================================
	//SORTING DATA ALPHABETICALLY
	cout << "Alphabetically Sorted Data" << endl;
		for(int i=0;i<10-1;i++){
		for(int j=0;j<10-i-1;j++){
			if(myStringCompare(lengthSorted[j], lengthSorted[j+1])>0){
				char temp[1][9];
				char temp2[1][2];
				myStringCopy(temp[0], lengthSorted[j]);
				myStringCopy(lengthSorted[j], lengthSorted[j+1]);
				myStringCopy(lengthSorted[j+1], temp[0]);
				
				myStringCopy(temp2[0], order[j]);
				myStringCopy(order[j], order[j+1]);
				myStringCopy(order[j+1], temp2[0]);
			}
		}
	}
	//PRINTING/WRITING ALPHABETICALLY SORTED DATA TO TERMINAL AND TEXT FILE
	ofstream write2;
	write2.open(outputName2);
	for(int i=0;i<10;i++){
		cout << order[i] << " " << lengthSorted[i] << endl;
		write2 << order [i] << " " << lengthSorted[i] << endl;
	}
	cout << "===================" << endl;
	//====================================================================================
	
	//CLOSING/RETURN
	read.close();
	write.close();
	write2.close();
	return 0;
	//
}

//COPIES SOURCE CSTRING TO DESTINATION CSTRING
void myStringCopy(char destination[], const char source[]){
	for(int i=0;i<8;i++){
		if(source[i]=='\0'){
			destination[i]='\0';
			break;
		}
		destination[i]=source[i];
	}
}

//RETURNS LENGTH OF PROVIDED CSTRING
int myStringLength(const char str[]){
	int strLen=0;
	for(int i=0;i<8;i++){
		if(str[i]=='\0'){
			break;
		}
		else{
			strLen++;
		}
	}
	return strLen;
}

//RETURNS -1 IF STR1 COMES BEFORE STR2 ALPHABETICALLY
//RETURNS 1 IF STR1 COMES AFTER STR2 ALPHABETICALLY
//RETURNS 0 IF STR1 AND STR2 ARE EQUAL ALPHABETICALLY
int myStringCompare(const char str1[], const char str2[]){
	for(int i=0;i<9;i++){
		if(str1[i]<str2[i]){
			return -1;
		}
		if(str1[i]>str2[i]){
			return 1;
		}	
	}
	return 0;
}

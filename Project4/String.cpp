#include <iostream>
#include <fstream>
#include "String.h"
using namespace std;

//copies source string to destination string
char * String::myStringCopy(char * destination, const char * source){
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
//adds source string to end of destination string
char * String::myStringCat(char * destination, const char * source){
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
//returns 0 if str1 and str2 are equal
//returns 1 if str1 comes before str2 alphabetically
//returns -1 if str2 comes before str1 alphabetically
int String::myStringCompare(const char * str1, const char * str2){
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

//returns length of str
size_t String::myStringLength(const char * str){
	size_t count=0;
	for(;*str!='\0';str++){
		count++;
	}
	return count;
}

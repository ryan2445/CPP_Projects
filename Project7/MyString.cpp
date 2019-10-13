//Ryan Hoffman - CS202 - Project 7
#include <iostream>
#include <fstream>
#include <string.h>
#include "MyString.h"
using namespace std;

//Default constructor
MyString::MyString(){
	m_buffer=NULL;
	m_size=0;
}

//Parameterized constructor
MyString::MyString(const char * str){
	int length = strlen(str);
	length++;
	m_size =length;
	buffer_allocate(length);
	strcpy(m_buffer, str);
}

//Copy constructor
MyString::MyString(const MyString & other_myStr){
	int length=strlen(other_myStr.m_buffer);
	length++;
	m_size=length;
	buffer_allocate(length);
	strcpy(m_buffer, other_myStr.m_buffer);
}

//Deconstructor
MyString::~MyString(){
	buffer_deallocate();
}

//returns size of string
size_t MyString::size() const{
	return m_size;
}

//returns length of string
size_t MyString::length() const{
	size_t length=strlen(m_buffer);
	return length;
}

//returns char * equivalent of m_buffer
const char * MyString::c_str() const{
	int length=strlen(m_buffer);
	length++;
	char * str=new char[length];
	strcpy(str, m_buffer);
	return str;
}

//tests if 2 strings are equal
bool MyString::operator== (const MyString & other_myStr) const{
	if(strcmp(m_buffer, other_myStr.m_buffer)==0){
		return 1;
	}
	return 0;
}  

//sets strings equal to each other
MyString & MyString::operator= (const MyString & other_myStr){
	delete [] m_buffer;
	int length=strlen(other_myStr.m_buffer);
	length++;
	buffer_allocate(length);
	strcpy(m_buffer, other_myStr.m_buffer);
	return *this;
}

//Concats strings
MyString MyString::operator+ (const MyString & other_myStr) const{
	char size[m_size+other_myStr.size()];
	strcpy(size, c_str());
	strcat(size, other_myStr.c_str());
	return MyString(size);
}

//returns char at index
char & MyString::operator[] (size_t index){
	return m_buffer[index];
}

//returns const char at index
const char & MyString::operator[] (size_t index) const{
	return m_buffer[index];
}

//prints m_buffer
std::ostream & operator<<(std::ostream & os, const MyString & myStr){
	os << myStr.c_str() << endl;
}

//deletes string data
void MyString::buffer_deallocate(){
	delete [] m_buffer;
	m_size=0;
}

//allocates memory for string
void MyString::buffer_allocate(size_t size){
	try{
		m_buffer = new char[size];
	}
	catch(const std::bad_alloc & ex){
		cout << "bad alloc" << endl;
		throw;
	}
}



















































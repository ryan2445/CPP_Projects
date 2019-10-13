//Ryan Hoffman - CS202 - Project 7
#include <iostream>
#include <fstream>
#include <string.h>
#include "MyString.h"
using namespace std;

int main(){
	//(1) Default constructor
	MyString ms_default;
	//(2) Parameterized constructor
	MyString ms_parameterized("MyString parameterized constructor!");
	//(3) Copy constructor
	MyString ms_copy(ms_parameterized);
	//(4) Delete test
	MyString * ms_Pt= new MyString("MyString to be deleted...");
	delete ms_Pt;
	ms_Pt=NULL;
	//(5), (6) Size and length test
	MyString ms_size_length("Size and length test");
	cout << ms_size_length.size() << endl;
	cout << ms_size_length.length() << endl;
	//(7) C-String test
	MyString ms_toCstring("C-String equivalent successfully obtained!");
	cout << ms_toCstring.c_str() << endl;
	//(8) Same/Different string test
	MyString ms_same1("The same"), ms_same2("The same");
	if(ms_same1==ms_same2){
		cout << "Same success" << endl;
	}
	MyString ms_different("The same (NOT)");
	if(!(ms_same1==ms_different)){
		cout << "Different success" << endl;
	}
	//(9) '=' assignment operator overload test
	MyString ms_assign("Before assignment");
	ms_assign=MyString("After performing assignment");
	cout << ms_assign;
	//(10) '+' assignment operator overload test
	MyString ms_append1("The first part");
	MyString ms_append2(" and the second");
	MyString ms_concat=ms_append1+ms_append2;
	cout << ms_concat;
	//(11) bracket index access test
	MyString ms_access("Access successful (NOT)");
	ms_access[17]=0;
	//(12) '<<' operator overload test
	cout << ms_access;
	return 0;
}

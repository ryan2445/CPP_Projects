//RYAN HOFFMAN - CS202 PROJECT 9
#include <iostream>
using namespace std;

#include "ArrayQueue.h"
#include "DataType.h"
#include "NodeQueue.h"

int main(){
DataType d1(1, 1.1);
DataType d2(2, 2.2);
//default constructor
ArrayQueue a1;
//paramterized constructor
ArrayQueue a2(5, d1);
cout << endl << "ARRAY QUEUE TESTS:-----------------------------------------------";
cout << endl << "Paramterized Constructor: " << endl;
cout << a2;
ArrayQueue a3;
a3=a2;
cout << endl << "'=' Operator Overload: " << endl;
cout << a3;
ArrayQueue a4(a2);
cout << endl << "Copy Constructor: " << endl;
cout << a4;
a2.push(d2);
cout << endl << "Push Function: " << endl;
cout << a2;
cout << endl << "Size: " << a2.size() << endl;
cout << endl << "Empty?: " << boolalpha << a2.empty() << endl;
a2.pop();
cout << endl << "Pop Function: " << endl;
cout << a2;
cout << endl << "Full?: " << boolalpha << a2.full() << endl;
cout << endl << "Clear Function: " << endl;
a2.clear();
cout << a2;

cout << endl << "NODE QUEUE TESTS:-----------------------------------------------" << endl << endl;
//default constructor
NodeQueue n1;
//paramterized constructor
NodeQueue n2(5, d1);
cout << "Paramterized Constructor:" << endl;
cout << n2;
cout << endl << "Empty?: " << boolalpha << n2.empty() << endl;
cout << endl << "Push Function: " << endl;
n2.push(d2);
cout << n2;
cout << endl << "Front Element: " << n2.front() << endl;
cout << endl << "Back Element: " << n2.back() << endl;
cout << endl << "Pop Function: " << endl;
n2.pop();
cout << n2;
cout << endl << "Size: " << n2.size() << endl;
cout << endl << "Clear Function: " << endl;
n2.clear();
cout << n2;
cout << endl;
return 0;
}

//Ryan Hoffman - CS202 - Project 10
#include <iostream>
using namespace std;
#include "ArrayStack.h"
#include "NodeStack.h"
int main(){
cout << "----------------------------------";
cout << endl << "Array Stack Tests";
//default constructor (prints nothing)
ArrayStack<int> a1;
cout << a1;

cout << endl << "Paramterized Constructor" << endl;
ArrayStack<int> a2(5, 3);
cout << a2 << endl;

cout << "Copy Constructor" << endl;
ArrayStack<double> a3(5, 3.1);
ArrayStack<double> a4(a3);
cout << a4 << endl;

cout << "Equals Operator Overload" << endl;
ArrayStack<double> a5;
a5=a3;
cout << a5 << endl;

cout << "Push Function" << endl;
a3.push(4.1);
cout << a3 << endl;

cout << "Pop Function" << endl;
a3.pop();
cout << a3;
cout << "----------------------------------" << endl;


cout << "Node Stack Tests" << endl;
//default constructor (prints nothing)
NodeStack<int> n1;
cout << n1;

cout << endl << "Paramterized Constructor" << endl;
NodeStack<int> n2(5, 4);
cout << n2 << endl;

cout << "Copy Constructor" << endl;
NodeStack<double> n3(5, 4.1);
NodeStack<double> n4(n3);
cout << n4 << endl;

cout << "Equals Operator Overload" << endl;
NodeStack<double> n5;
n5=n3;
cout << n5 << endl;

cout << "Push Function" << endl;
n3.push(5.1);
cout << n3 << endl;

cout << "Pop Function" << endl;
n3.pop();
cout << n3;
cout << "----------------------------------" << endl;

return 0;
}

//RYAN HOFFMAN - CS202 - PROJECT 8
#include <iostream>

#include "ArrayList.h"
#include "NodeList.h"

using namespace std;

int main(){	
	 DataType d1(1, 1.0);
    DataType d2(2, 2.0);
    DataType d3(3, 3.0);
    DataType d4(4, 4.0);
    DataType d5(5, 5.0);
    DataType d6(6, 6.0);
    DataType d7(7, 7.0);
    DataType d8(8, 8.0);
    DataType d9(9, 9.0);
    DataType d10(10, 10.0);
    
    NodeList n1(5, d1);
    Node * ptr1 = NULL;

    n1[0] = d2;
    n1[3] = d3;

    cout << endl << n1 << endl << endl;
    
    cout << "Insert After:" << endl;

    n1.insertAfter(d2, d4);
    std::cout << n1 << endl << endl;

    cout << "Insert Before:" << endl;

    n1.insertBefore(d2, d4);
    std::cout << n1 << endl << endl;
    
    cout << "Is Empty?: " << n1.empty() << endl << endl;
    
    cout << "Size: " << n1.size() << endl;

    cout << endl << "Erase:" << endl;

    ptr1 = n1.erase(d1);

    cout << n1 << endl << endl;

    n1.clear();
    

  return 0;
}

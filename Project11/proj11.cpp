//Ryan Hoffman - CS202 Project 11
#include <iostream>
#include <fstream>

#include <vector>

#include "VectorRecursion.h"
using namespace std;

int main(){

  // Vector creation
  std::vector<int> vecInt;
  
  // Vector population with input values
  std::ifstream fin("RandomData.txt");
  while(fin){
    int fin_in;
    fin >> fin_in;
    if (!fin)
      break;
    vecInt.push_back( fin_in );
  }
  
  std::vector<int> vecIntCopy(vecInt);
  
  cout << "-----SORTING VECTOR-----" << endl;
  vector_resort(vecInt, vecInt.size());
  cout << "-----VECTOR SORTED-----" << endl;
  
  cout << "-----SEARCHING FOR VALUE-----" << endl;
  int value=23;
  cout << "Index of value " << value << ": " << vector_research(vecInt, value, 0, (vecInt.size()-1)) << endl;
  
  // Vector indexing and output ( using operator[] or at() )
  //for (size_t i=0; i<vecInt.size(); ++i){
  //  std::cout << vecInt[i] << " same as " << vecInt.at(i) << std::endl; 
  //}
  
  // Vector indexing and output ( using iterator )
  for (std::vector<int>::iterator it=vecInt.begin(); it!=vecInt.end(); ++it){
    std::cout << *it << std::endl; 
  }

  return 0;
}

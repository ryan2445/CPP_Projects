//Ryan Hoffman - CS202 - Project X
#include <iostream>
#include <fstream>
#include "DataType.h"
#include "SmartPtr.h"
using namespace std;

//default constructor
SmartPtr::SmartPtr(){
	m_ptr=new DataType;
   m_refcount=new size_t;
   *m_refcount=1;
   cout << "SmartPtr Default Constructor for new allocation, RefCount=" << *m_refcount << endl;
}

//parameterized constructor
SmartPtr::SmartPtr(DataType * data){
	m_ptr=data;
	m_refcount=new size_t;
   if (!data){
    *m_refcount=0;
   } 
   else{
    *m_refcount=1;
   }
   cout << "SmartPtr  Parametrized  Constructor  from data pointer, RefCount=" << *m_refcount << endl;
}

//copy constructor
SmartPtr::SmartPtr(const SmartPtr & other){
	if(!other.m_ptr){
		m_refcount=new size_t;
		*m_refcount=0;
	}
	else{
   	m_refcount=other.m_refcount;
   	(*m_refcount)++;
   }
   m_ptr = other.m_ptr;
   cout << "SmartPtr  Copy  Constructor,  RefCount=" << *m_refcount << endl;
}

//deconstructor
SmartPtr::~SmartPtr(){
	if(*m_refcount>0){
   	(*m_refcount)--;
   }
   cout << "SmartPtr  Destructor,  RefCount=" << *m_refcount << endl;
   if (*m_refcount<=0){
   	delete m_ptr;
      delete m_refcount;
   }
}

//= operator overload
SmartPtr & SmartPtr::operator=(const SmartPtr &rhs){
	if(*m_refcount<=0){
       delete m_ptr;
       delete m_refcount;
   }
  	if (!rhs.m_ptr){
   	m_refcount=new size_t;
     	*m_refcount=0;
   }
   else{
   	m_refcount = rhs.m_refcount;
   	(*m_refcount)++;
    }
    m_ptr = rhs.m_ptr;
    cout << "SmartPtr  Copy  Assignment,  RefCount=" << *m_refcount << endl;
    return *this;
}

//* operator overload
DataType & SmartPtr::operator*(){
    return *m_ptr;
}

//-> operator overload
DataType * SmartPtr::operator->(){
    return m_ptr;
}

//RYAN HOFFMAN - CS202 - PROJECT 8
#include "ArrayList.h"
#include "DataType.h"

//default constructor
ArrayList::ArrayList(){
	m_array=NULL;
	m_size=0;
	m_maxsize=0;
}

//default constructor
ArrayList::ArrayList(size_t count, const DataType & value){
	m_array=new DataType[count];
	for(int i=0;i<count;i++){
		m_array[i]=value;
	}
	m_size=count;
	m_maxsize=count;
}

//parameterized constructor
ArrayList::ArrayList(const ArrayList & other){
	m_array=new DataType[other.m_size];
	for(int i=0;i<other.m_size;i++){
		m_array[i]=other.m_array[i];
	}	
	m_size=other.m_size;
	m_maxsize=other.m_size;
}

//deconstructor
ArrayList::~ArrayList(){
	delete [] m_array;
}

//equals operator overload
ArrayList & ArrayList::operator= (const ArrayList & rhs){
	delete [] m_array;
	m_array=new DataType[rhs.m_size];
	for(int i=0;i<rhs.m_size;i++){
		m_array[i]=rhs.m_array[i];
	}
	m_size=rhs.m_size;
	m_maxsize=rhs.m_maxsize;
	return *this;
}

//front function
DataType * ArrayList::front(){
	for(int i=0;i<m_size;i++){
		if(m_array[i].getIntVal() && m_array[i].getDoubleVal()){
			return & m_array[i];
		}
	}
	return NULL;
}

//back function 
DataType * ArrayList::back(){
	for(int i=m_size;i>0;i--){
		if(m_array[i].getIntVal() && m_array[i].getDoubleVal()){
			return & m_array[i];
		}
	}
	return NULL;
}

//find function
DataType * ArrayList::find(const DataType & target, DataType * & previous, const DataType * start){
	for(int i=0;i<m_size;i++){
		if(m_array[i]==target){
			return & m_array[i];
		}
		if(i!=0){
		previous=&m_array[i-1];
		}
	}
	return NULL;
}

//insert after function
DataType * ArrayList::insertAfter(const DataType & target, const DataType & value){
	DataType * inserted = NULL;
	DataType * prev = NULL;
	int count=0;
	DataType * tar=find(target, prev);
	if(tar!=NULL){
		if(m_size>=m_maxsize){
			DataType * newArr=new DataType[m_size+1];
			for(int i=0;i<m_size+1;i++){
				if(&m_array[i]==tar){
					newArr[i]=value;
					count++;
				}
				else{
					newArr[i]=m_array[i+count];
				}
			}
		}
	}
	return inserted;
}

//insert before function
DataType * ArrayList::insertBefore(const DataType & target, const DataType & value){
	int count=0;
	DataType * inserted=NULL;
	DataType * prev=NULL;
	DataType * tar=find(target, prev);
	if(tar!=NULL){
		if(m_size>=m_maxsize){
			DataType * newArr=new DataType[m_size+1];
		for(int i=0;i<m_size+1;i++){
			if(&m_array[i]==tar){
				newArr[i]=value;
				count++;
			}
			else{
				newArr[i]=m_array[i-count];
			}
		}
	  }
	}
	return inserted;
}

//erases array list
DataType * ArrayList::erase(const DataType & target){
	DataType * curr=m_array;
	while(curr!=NULL){
		if(target==*curr){
			for(int i=1;i<m_size;i++){
				m_array[i-1]=m_array[i];
			}
		}	
	}
	return NULL;
}

//[] operator overload function
DataType & ArrayList::operator[] (size_t position){
	return m_array[position];
}

//returns size
size_t ArrayList::size() const{
	return m_size;
}

//checks if empty
bool ArrayList::empty() const{
	if(m_size==0 && m_array==NULL){
		return 1;
	}
	return 0;
}

//deletes m_array
void ArrayList::clear(){
	delete [] m_array;	
	m_array=NULL;
	m_size=0;
	m_maxsize=0;
}

//resizes m_array
void ArrayList::resize(size_t count){
	DataType * temp=new DataType[m_size];
	temp=m_array;
	delete [] m_array;
	m_array=new DataType[count];
	m_array=temp;
}

//print operator overload
std::ostream & operator<<(std::ostream & os, const ArrayList & arrayList){
	int size=arrayList.m_size;
	for(int i=0;i<size;i++){
		os << arrayList.m_array[i] << " ";
	}
	return os;
}






























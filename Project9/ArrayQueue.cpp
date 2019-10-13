//RYAN HOFFMAN - CS202 PROJECT 9
#include <iostream>
using namespace std;

#include "ArrayQueue.h"
#include "DataType.h"

//default constructor
ArrayQueue::ArrayQueue(){
	m_front=0;
	m_back=0;
	m_size=0;
}

//paramterized constructor
ArrayQueue::ArrayQueue(size_t count, const DataType & value){
	m_front=0;
	m_back=0;
	m_size=0;
	for(int i=0;i<count;i++){
	m_array[m_back]=value;
	m_back=(m_back+1)%ARRAY_MAX;
	m_size++;
	}
}

//copy constructor
ArrayQueue::ArrayQueue(const ArrayQueue & other){
	m_front=other.m_front;
	m_back=other.m_back;
	m_size=other.m_size;
	for(int i=0;i<other.m_size;i++){
		m_array[i]=other.m_array[i];
	}
}

//deconstructor (no need to implement)
ArrayQueue::~ArrayQueue(){
}

//= operator overload
ArrayQueue & ArrayQueue::operator= (const ArrayQueue & rhs){
	m_front=rhs.m_front;
	m_back=rhs.m_back;
	m_size=rhs.m_size;
	for(int i=0;i<rhs.m_size;i++){
		m_array[i]=rhs.m_array[i];
	}
}


//returns front value
DataType & ArrayQueue::front(){
	return m_array[m_front];
}

//returns const front value
const DataType & ArrayQueue::front() const{
	return m_array[m_front];
}

//returns back value
DataType & ArrayQueue::back(){
	return m_array[m_back];
}

//returns const back value
const DataType & ArrayQueue::back() const{
	return m_array[m_back];
}

//pushes value at end of queue
void ArrayQueue::push(const DataType & value){
	m_array[m_back]=value;
	m_back=(m_back+1)%ARRAY_MAX;
	m_size++;
}

//removes value at beginning of queue
void ArrayQueue::pop(){
	m_front=(m_front+1)%ARRAY_MAX;
	m_size--;
}

//returns queue size
size_t ArrayQueue::size() const{
	return m_size;
}

//returns if queue is empty
bool ArrayQueue::empty() const{
	if(m_size==0){
		return 1;
	}
	return 0;
}

//returns if queue is full
bool ArrayQueue::full() const{
	if(m_size==ARRAY_MAX){
		return 1;
	}
	return 0;
}

//clears queue
void ArrayQueue::clear(){
	m_front=0;
	m_back=0;
	m_size=0;
}

//prints queue
void ArrayQueue::serialize(std::ostream & os) const{
	if(m_size==0){
		cout << "Array Queue is Empty" << endl;
		return;
	}
	for(int i=0;i<m_size;i++){
		os << i << ": " << m_array[m_front+i] << endl;
	}
}

//<< operator overload
std::ostream & operator<<(std::ostream & os, const ArrayQueue & arrayQueue){
	arrayQueue.serialize(os);
	return os;
}






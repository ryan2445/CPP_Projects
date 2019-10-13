//RYAN HOFFMAN - CS202 PROJECT 9
#include <iostream>
using namespace std;

#include "NodeQueue.h"
#include "DataType.h"

//default constructor
NodeQueue::NodeQueue(){
	m_front=NULL;
	m_back=NULL;
	m_size=0;
}

//paramterized constructor
NodeQueue::NodeQueue(size_t size, const DataType & value){
	m_front=NULL;
	m_back=NULL;
	m_size=0;
	m_front=new Node(value);
	Node * curr=m_front;
	for(int i=0;i<size-1;i++){
		curr->m_next=new Node(value);
		curr=curr->m_next;
		m_back=curr;
		m_size++;
	}
	curr=NULL;
	delete curr;
}

//copy constructor
NodeQueue::NodeQueue(const NodeQueue & other){
	m_size=0;
	m_front=NULL;
	m_back=NULL;
	Node * curr2=other.m_front;
	m_front=new Node(curr2->data());
	Node * curr=m_front;
	for(int i=0;i<other.m_size;i++){
		curr->m_next=new Node(curr2->data());
		curr=curr->m_next;
		m_back=curr;
		m_size++;
	}
	curr=NULL;
	curr2=NULL;
	delete curr;
	delete curr2;
}

//destructor
NodeQueue::~NodeQueue(){
	cout << "NodeQueue Destructor" << endl;
	Node * curr=m_front;
	while(curr){
		delete curr;
		curr=curr->m_next;
	}
	curr=NULL;
}

//= operator overload
NodeQueue& NodeQueue::operator= (const NodeQueue & rhs){
	m_size=0;
	m_front=NULL;
	m_back=NULL;
	Node * curr2=rhs.m_front;
	m_front=new Node(curr2->data());
	Node * curr=m_front;
	for(int i=0;i<rhs.m_size;i++){
		curr->m_next=new Node(curr2->data());
		curr=curr->m_next;
		m_back=curr;
		m_size++;
	}
	curr2=NULL;
	curr=NULL;
	delete curr2;
	delete curr;
	return *this;
}

//returns front data value
DataType & NodeQueue::front(){
	return m_front->data();
}

//returns const front data value
const DataType & NodeQueue::front() const{
	return m_front->data();
}

//returns back value
DataType & NodeQueue::back(){
	return m_back->data();
}

//returns const back value
const DataType & NodeQueue::back() const{
	return m_back->data();
}

//returns if node queue is empty
bool NodeQueue::empty() const{
	if(m_front==NULL){
		return 1;
	}
	return 0;
}

//pushes value to end of queue
void NodeQueue::push(const DataType & value){
	Node * ptr=new Node(value);
	if(empty()){
		m_front=ptr;
		m_back=ptr;
		return;
	}
	m_back->m_next=ptr;
	m_back=ptr;
	m_size++;
}

//removes value from front of queue
void NodeQueue::pop(){
	m_size--;
	m_front=m_front->m_next;
}

//returns size of queue
size_t NodeQueue::size() const{
	return m_size+1;
}

//returns if queue is full
bool NodeQueue::full() const{
	return 0;
}

void NodeQueue::clear(){
	Node * curr=m_front;
	Node * temp=NULL;
	for(int i=0;i<m_size+1;i++){
		temp=curr;
		curr=curr->m_next;
		delete temp;
	}
	m_front=NULL;
	m_back=NULL;
}

//<< operator overload
std::ostream & operator<<(std::ostream & os, const NodeQueue & nodeQueue){
	nodeQueue.serialize(os);
	return os;
}

//prints queue
void NodeQueue::serialize(std::ostream & os) const{
	Node * curr=m_front;
	if(curr==NULL){
		cout << "Node Queue is Empty" << endl;
		return;
	}
	for(int i=0;i<m_size+1;i++){
		os << i << ": " << curr->data() << endl;
		curr=curr->m_next;
	}
}











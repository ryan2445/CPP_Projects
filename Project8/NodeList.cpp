//RYAN HOFFMAN - CS202 - PROJECT 8
#include "NodeList.h"
#include "DataType.h"

//default constructor
NodeList::NodeList(){
	m_head=NULL;
}

//Parameterized constructor
NodeList::NodeList(size_t count, const DataType & value){
	Node * temp=NULL;
	if(count==0){
		m_head=NULL;
	}
	else{
		m_head=new Node(value, NULL);
		temp=m_head;		
	}
	for(int i=1;i<count;i++){
		temp->m_next=new Node(value, NULL);
		temp=temp->m_next;
	}
	temp->m_next=NULL;
}

//Copy constructor
NodeList::NodeList(const NodeList & other){
	m_head=new Node(other.m_head->data(), NULL);
	Node * temp=m_head;
	Node * temp2=other.m_head;
	while(temp2->m_next!=NULL){
		temp2=temp2->m_next;
		temp->m_next=new Node(temp2->data(), NULL);
		temp=temp->m_next;
	}
	temp->m_next=NULL;
}

//deconstructor
NodeList::~NodeList(){
	Node * curr=m_head;
	Node * next;
	while(next!=NULL){
		next=curr->m_next;
		delete curr;
	}
}

//= operator overload
NodeList & NodeList::operator= (const NodeList & rhs){
	m_head=rhs.m_head;
}

Node * NodeList::front(){
	return m_head;
}

Node * NodeList::back(){
	Node * curr=m_head;
	while(curr->m_next!=NULL){
		curr=curr->m_next;
	}
	return curr;
}

//find function
Node * NodeList::find(const DataType & target, Node * & previous, const Node * start){
	Node * curr=m_head;
	while(curr!=NULL&&curr->m_next!=NULL){
		if(curr->data()==target){
			if(curr!=NULL){
				previous=curr;
			}
			else{
				previous=NULL;
			}
			return curr->m_next;
		}
		curr=curr->m_next;
	}
	previous=NULL;
	return NULL;
}

//insert after function
Node * NodeList::insertAfter(const DataType & target, const DataType & value){
	Node * curr=m_head;
	while(curr!=NULL){
		if(curr->data()==target){
			curr->m_next=new Node(value, curr->m_next);
			return curr->m_next;
		}
		curr=curr->m_next;
	}
	return NULL;
}

//insert before function
Node * NodeList::insertBefore(const DataType & target, const DataType & value){
	Node * curr=m_head;
	while(curr!=NULL){
		if(curr->data()==target){
			curr=new Node(value, curr->m_next);
			return curr;
		}
		curr=curr->m_next;
	}
	return NULL;
}

//erase function 
Node * NodeList::erase(const DataType & target){
	Node * curr=m_head;
	while(curr!=NULL){
		if(curr->data()==target){
			delete curr;
			curr=curr->m_next;
			return curr;
		}
		curr=curr->m_next;
	}
	return NULL;
}

//bracket operator overload function
DataType & NodeList::operator[] (size_t position){
	Node * curr=m_head;
	for(int i=0;i<position;i++){
		curr++;
	}
	return curr->data();	
}

//const bracket operator overload
const DataType & NodeList::operator[] (size_t position) const{
	Node * curr=m_head;
	for(int i=0;i<position;i++){
		curr++;
	}
	return curr->data();	
}

//size return function
size_t NodeList::size() const{
	int count=0;
	Node * curr=m_head;
	while(curr!=NULL){
		curr=curr->m_next;
		count++;
	}
	return count;
}

//check if empty function
bool NodeList::empty() const{
	Node * curr=m_head;
	if(curr!=NULL){
		return 0;
	}
	return 1;
}

//clear function
void NodeList::clear(){
    Node* current = m_head;
    Node* previous = m_head;
    while (current != NULL)
    {
        current = current->m_next;
        delete previous;
        previous = current;
    }
    m_head = NULL;
}

//print operator overload function
std::ostream & operator<<(std::ostream & os, const NodeList & nodeList){
	for(int i=0;i<nodeList.size();i++){
		os << nodeList[i];
	}
	return os;
}





























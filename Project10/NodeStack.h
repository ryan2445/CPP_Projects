//Ryan Hoffman - CS202 - Project 10
#ifndef _NODESTACK_H_
#define _NODESTACK_H_
#include <iostream>
using namespace std;

template <class T> class Node;
template <class T> class NodeStack;
template <class T> std::ostream & operator<< (std::ostream & os, const NodeStack<T> & nodeStack);

template <class T>
class Node{
 friend class NodeStack<T>;
 public:
 Node();
 Node(const T & data, Node<T> * next = NULL);
 T & data();
 const T & data() const;
 private:
 Node<T> * m_next;
 T m_data;
};

template <class T>
Node<T>::Node(){
	m_next=NULL;
	m_data=T();
}

template <class T>
Node<T>::Node(const T & data, Node<T> * next){
	m_next=next;
	m_data=data;
}

template <class T>
T & Node<T>::data(){
	return m_data;
}

template <class T>
const T & Node<T>::data() const{
	return m_data;
}

template <class T>
class NodeStack{
 friend std::ostream & operator<< <> (std::ostream & os, const NodeStack<T> & nodeStack); //(i)
 public:
 NodeStack(); //(1)
 NodeStack(size_t count, const T & value); //(2)
 NodeStack(const NodeStack<T> & other); //(3)
 ~NodeStack(); //(4)
 NodeStack<T> & operator= (const NodeStack<T> & rhs); //(5)

 T & top(); //(6a)
 const T & top() const; //(6b)

 void push(const T & value); //(7)
 void pop(); //(8)
 size_t size() const; //(9)
 bool empty() const; //(10)
 bool full() const; //(11)
 void clear(); //(12)
 void serialize(std::ostream & os) const; //(13)
 private:
 Node<T> * m_top;
};

template <class T>
NodeStack<T>::NodeStack(){
	m_top=NULL;
}

template <class T>
NodeStack<T>::NodeStack(size_t count, const T & value){
	m_top=NULL;
	for(int i=0;i<count;i++){
		if(empty()){
			m_top=new Node<T>(value);
		}
		else{
			m_top=new Node<T>(value, m_top);
		}
	}
}

template <class T>
NodeStack<T>::NodeStack(const NodeStack<T> & other){
	Node<T> * curr;
	m_top=NULL;
	size_t size=other.size();
	while(size){
		curr=other.m_top;
		if(empty()){
			m_top=new Node<T>(curr->data());
		}
		else{
			m_top=new Node<T>(curr->data(), m_top);
		}
		size--;
	}
}

template <class T>
NodeStack<T>::~NodeStack(){
//	Node<T> * curr=m_top;
//	while(curr){
//		delete curr;
//		curr=curr->m_next;
//	}
	clear();
}

template <class T>
NodeStack<T> & NodeStack<T>::operator= (const NodeStack<T> & rhs){
	Node<T> * curr;
	m_top=NULL;
	size_t size=rhs.size();
	while(size){
		curr=rhs.m_top;
		if(empty()){
			m_top=new Node<T>(curr->data());
		}
		else{
			m_top=new Node<T>(curr->data(), m_top);
		}
		size--;
	}
}

template <class T>
T & NodeStack<T>::top(){
	return m_top->data();
}

template <class T>
const T & NodeStack<T>::top() const{
	return m_top->data();
}

template <class T>
void NodeStack<T>::push(const T & value){
	if(empty()){
		m_top=new Node<T>(value);
	}
	else{
		m_top=new Node<T>(value, m_top);
	}
}

template <class T>
void NodeStack<T>::pop(){
	if(m_top!=NULL){
		Node<T> * temp=m_top;
		m_top=m_top->m_next;
		delete temp;
	}
}

template <class T>
size_t NodeStack<T>::size() const{
	size_t size=0;
	Node<T> * curr=m_top;
	while(curr){
		size++;
		curr=curr->m_next;
	}
	return size;
}

template <class T>
bool NodeStack<T>::empty() const{
	if(m_top==NULL){
		return 1;
	}
	return 0;
}

template <class T>
bool NodeStack<T>::full() const{
	return 0;
}

template <class T>
void NodeStack<T>::clear(){
	Node<T> * curr=m_top;
	while(curr){
		pop();
		curr=curr->m_next;
	}
}

template <class T>
void NodeStack<T>::serialize(std::ostream & os) const{
	Node<T> * curr=m_top;
	int i=0;
	while(curr){
		os << i << ": " << curr->data() <<endl;
		curr=curr->m_next;
		i++;
	}
}

template <class T>
std::ostream & operator<< (std::ostream & os, const NodeStack<T> & nodeStack){
	nodeStack.serialize(os);
	return os;
}
#endif

//Ryan Hoffman - CS202 - Project 10
#ifndef _ARRAYSTACK_H_
#define _ARRAYSTACK_H_
#include <iostream>
using namespace std;

template <class T> class ArrayStack;
template <typename T> const size_t MAX_STACKSIZE=1000;
template <class T> std::ostream & operator<< (std::ostream & os, const ArrayStack<T> & arrayStack);

template <class T>
class ArrayStack{
 friend std::ostream & operator<< <> (std::ostream & os, const ArrayStack<T> & arrayStack); //(i)
 public:
 ArrayStack(); //(1)
 ArrayStack(size_t count, const T & value); //(2)
 ArrayStack(const ArrayStack<T> & other); //(3)
 ~ArrayStack(); //(4)
 ArrayStack<T> & operator= (const ArrayStack<T> & rhs); //(5)

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
 T m_container[MAX_STACKSIZE<T>];
 size_t m_top;
};

template <class T>
ArrayStack<T>::ArrayStack(){
	m_top=0;
}

template <class T>
ArrayStack<T>::ArrayStack(size_t count, const T & value){
	m_top=0;
	for(int i=0;i<count;i++){
		m_container[m_top]=value;
		m_top++;
	}
}

template <class T>
ArrayStack<T>::ArrayStack(const ArrayStack<T> & other){
	m_top=0;
	for(int i=0;i<other.m_top;i++){
		m_container[m_top]=other.m_container[m_top];
		m_top++;
	}
}

template <class T>
ArrayStack<T>::~ArrayStack(){
}

template <class T>
ArrayStack<T> & ArrayStack<T>::operator= (const ArrayStack<T> & rhs){
	m_top=0;
	for(int i=0;i<rhs.m_top;i++){
		m_container[m_top]=rhs.m_container[m_top];
		m_top++;
	}
	return *this;
}

template <class T>
T & ArrayStack<T>::top(){
	return m_container[m_top-1];
}

template <class T>
const T & ArrayStack<T>::top() const{
	return m_container[m_top-1];
}

template <class T>
void ArrayStack<T>::push(const T & value){
	m_container[m_top]=value;
	m_top++;
}

template <class T>
void ArrayStack<T>::pop(){
	m_top--;
}

template <class T>
size_t ArrayStack<T>::size() const{
	return m_top;
}

template <class T>
bool ArrayStack<T>::empty() const{
	if(m_top==0){
		return 1;
	}
	return 0;
}

template <class T>
bool ArrayStack<T>::full() const{
	if(m_top>=MAX_STACKSIZE<T>){
		return 1;
	}
	return 0;
}

template <class T>
void ArrayStack<T>::clear(){
	m_top=0;
}

template <class T>
void ArrayStack<T>::serialize(std::ostream & os) const{
	int count=0;
	for(int i=m_top-1;i>=0;i--){
		os << count << ": " << m_container[i] << endl;
		count++;
	}
}

template <class T>
std::ostream & operator<< (std::ostream & os, const ArrayStack<T> & arrayStack){
	arrayStack.serialize(os);
	return os;
}
#endif

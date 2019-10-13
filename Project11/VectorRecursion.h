//Ryan Hoffman - CS202 Project 11
#include <vector>

template <class T>
void vector_resort(std::vector<T> & v1, size_t size){
	if(size==1){
		return;
	}
	for(int i=0;i<size-1;i++){
		if(v1[i]>v1[i+1]){
			T vTemp;
			vTemp=v1[i];
			v1[i]=v1[i+1];
			v1[i+1]=vTemp;
		}
	}
	vector_resort(v1, size-1);
}

template <class T>
int vector_research(std::vector<T> &v1, const T & value, int left, int right){
	int mid=((left+right)/2);
	if(left>right){
		return -1;
	}
	if(v1[mid]<value){
		return vector_research(v1, value, (mid+1), right);
	}
	if(v1[mid]>value){
		return vector_research(v1, value, left, (mid-1));
	}
	return mid;
}

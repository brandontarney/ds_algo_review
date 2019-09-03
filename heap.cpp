/* 
   * Create a heap data structure
   *	Should include insert and delete
   */

#include <vector>
#include <iostream>
#include <exception>

using namespace std;

class NoDataException : public exception 
{
	virtual const char * what() const throw()
	{
		return ("No data available");
	}
} ;

template<typename T>
class MaxHeap
{
		vector<T> data;
	public:
		MaxHeap(){ cout<<"Default heap constructor"<<endl; };

		MaxHeap(vector<T> & inData)
		{
			this->data = inData;
			this->heapify();
		};

		void heapify()
		{
			cout<<"heapify, data.size == "<<this->data.size()<<endl;
			for (int i = 0; i < this->data.size(); i++)
			{
				this->heapifyUp(i);
			}
		};

		void printHeap()
		{
			cout<<"printHeap()"<<endl;
			for (int i = 0; i < this->data.size(); i++)
			{
				cout<<this->data[i]<<endl;
			}
		};

		void insert(T insertItem);
		T remove();
		void heapifyUp(int currentIdx);
		void heapifyDown(int currentIdx);
};

template<typename T>
void MaxHeap<T>::insert(T insertItem)
{
	cout<<"Insert "<<insertItem<<endl;
	//Insert the value at the end
	this->data.push_back(insertItem);
	cout<<"heap size: "<<data.size()<<endl;
	//Push this value up if it's larger than parent
	this->heapifyUp(data.size() - 1);
}

template<typename T>
T MaxHeap<T>::remove()
{
	cout<<"Remove()"<<endl;
	if (this->data.size() > 0)
	{
		//Swap the end & start
		T startVal = this->data[0] ;
		T endVal = this->data[data.size()-1];
		this->data[0] = endVal;
		this->data[data.size()-1] = startVal;

		//Get the actual value to return (what was first and is now last)
		T returnVal = this->data.back();
		this->data.pop_back();

		//Ensure the properties of the heap!
		this->heapifyDown(0);

		return (returnVal);
	}
	else
	{
		cout<<"NO DATA"<<endl;
		NoDataException noDataException;
		throw noDataException;
	}
}

template<typename T>
void MaxHeap<T>::heapifyUp(int currentIdx)
{
	cout<<"heapifyUp("<<currentIdx<<")"<<endl;
	if  (currentIdx != 0)
	{
		//Get the parent & current idx & values
		const T currentVal = this->data[currentIdx];
		const int parentIdx = (currentIdx-1)/2;
		const T parentVal = this->data[parentIdx];
		//If the parent is smaller than current, SWAP!
		if (parentVal < currentVal)
		{
			cout<<"parent("<<parentVal<<") < currentVal("<<currentVal<<")"<<endl;
			cout<<"swap parentIdx"<<parentIdx<<" with childIdx"<<currentIdx<<endl;
			//SWAP values
			this->data[parentIdx] = currentVal;
			this->data[currentIdx] = parentVal;
			if (parentIdx != 0)
			{
				cout<<"heapifyUp("<<parentIdx<<")"<<endl;
				this->heapifyUp(parentIdx);
			}
		}
	}
};

template<typename T>
void MaxHeap<T>::heapifyDown(int currentIdx)
{
	cout<<"heapifyDown("<<currentIdx<<")"<<endl;
	if  (currentIdx < (this->data.size() - 1) )
	{
		//Get the parent & current idx & values
		const T currentVal = this->data[currentIdx];
		const int leftChildIdx = (currentIdx * 2) + 1;
		const int rightChildIdx = (currentIdx * 2) + 2;
		const T leftChildVal = this->data[leftChildIdx];
		const T rightChildVal = this->data[rightChildIdx];
		if (currentVal < leftChildVal || currentVal < rightChildVal)
		{
			//Swap & heapify down
			if (leftChildVal > rightChildVal && leftChildIdx < this->data.size())
			{
				cout<<"currentVal("<<currentVal<<") < leftChildVal("<<leftChildVal<<")"<<endl;
				cout<<"swap currentIdx"<<currentIdx<<" with leftChildIdx"<<leftChildIdx<<endl;
				//SWAP values
				this->data[leftChildIdx] = currentVal;
				this->data[currentIdx] = leftChildVal;
				cout<<"heapifyDown("<<leftChildIdx<<")"<<endl;
				this->heapifyDown(leftChildIdx);
			}
			if (rightChildVal > leftChildVal && rightChildIdx < this->data.size())
			{
				//Swap & heapify down
				cout<<"currentVal("<<currentVal<<") < rightChildVal("<<rightChildVal<<")"<<endl;
				cout<<"swap currentIdx"<<currentIdx<<" with rightChildIdx"<<rightChildIdx<<endl;
				//SWAP values
				this->data[rightChildIdx] = currentVal;
				this->data[currentIdx] = rightChildVal;
				cout<<"heapifyDown("<<rightChildIdx<<")"<<endl;
				this->heapifyDown(rightChildIdx);
			}
		}
		else
		{
			cout<<"currentVal("<<currentVal<<") > children: "<<leftChildVal<<" "<<rightChildVal<<endl;
		}
	}
};


int main()
{
	cout<<"Main() start - build max heap"<<endl;
	vector<int> data = {1,2,3,4,5};
	MaxHeap<int> maxHeap(data);
	cout<<"created heap"<<endl<<endl;
	maxHeap.printHeap();
	cout<<"insert 9"<<endl<<endl;
	maxHeap.insert(9);
	maxHeap.printHeap();
	cout<<"remove"<<endl<<endl;
	int maxVal = maxHeap.remove();
	assert(maxVal == 9);
	maxHeap.printHeap();
	cout<<"remove"<<endl<<endl;
	maxVal = maxHeap.remove();
	assert(maxVal == 5);
	maxHeap.printHeap();
	return 0;
}

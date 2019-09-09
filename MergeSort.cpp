/*
	Implementation of mergesort
	@author Brandon Tarney
	@date	09/2019
	*/

#include <iostream>
#include <vector>
#include <deque>

using namespace std;

	template<class T>
void printData(vector<T> & input)
{
	for (auto x : input)
	{
		cout<<x<<endl;
	}
}

template<class T>
class MergeSort
{
	private:
	public:
		static void sort(vector<T> & input, const int low, const int high);
		static void merge(vector<T> & input, const int low, const int mid, const int high);
};

template<class T>
void MergeSort<T>::merge(vector<T> & input, const int low, const int mid, const int high)
{
	cout<<"merge: low"<<low<<" mid"<<mid<<" high"<<high<<endl;
	deque<T> vals1;
	deque<T> vals2;

	for (int i = low; i <= mid; i++)
	{
		vals1.push_back(input[i]);
	}
	for (int i = mid+1; i <= high; i++)
	{
		vals2.push_back(input[i]);
	}

	int inputPtr = low;

	while (!vals1.empty() && !vals2.empty() && inputPtr <= high)
	{
		if (vals1.front() < vals2.front())
		{
			input[inputPtr] = vals1.front();
			vals1.pop_front();
		}
		else
		{
			input[inputPtr] = vals2.front();
			vals2.pop_front();
		}
		inputPtr++;
	}

	//Only one of these two should occur!
	while (!vals1.empty())
	{
		//Push them onto input
		input[inputPtr] = vals1.front();
		vals1.pop_front();
	}
	while (!vals2.empty())
	{
		//Push them onto input
		input[inputPtr] = vals2.front();
		vals2.pop_front();
	}

	//printData<T>(input);
	
}

template<class T>
void MergeSort<T>::sort(vector<T> & input, const int low, const int high)
{
	if (low != high)
	{
		cout<<"sort: low"<<low<<" high"<<high<<endl;
		//First we call mergeSort on the 2 halves
		const int mid = (high + low) / 2;
		MergeSort<T>::sort(input, low, mid);
		MergeSort<T>::sort(input, mid+1, high);

		//Then we merge
		MergeSort<T>::merge(input, low, mid, high);
	}
}



int main()
{
	cout<<"MergeSort example"<<endl;
	vector<int> input = {1, 4, 5, 2, 5, 9};
	cout<<"INPUT:"<<endl;
	printData<int>(input);
	MergeSort<int>::sort(input, 0, input.size() - 1);
	cout<<"OUTPUT:"<<endl;
	printData<int>(input);
	return (0);
}





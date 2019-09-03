/*
   CPP Implementation of Quicksort
   @author	Brandon Tarney
   @date	09/2018
   */

/*
   quickSort()
	- recurisve (partition)
	- choose a partition idx & swap all values not below/above 
	- recurse on separate portions
	
	@param	inputVector
*/
#include <vector>
#include <iostream>
#include <fstream>

using namespace std;

template< class T >
void printData( vector<T> & data)
{
	for (auto x : data)
	{
		cout << x << endl;
	}
}

template< class T >
void logData( ofstream & logFile, vector<T> & data)
{
	for (auto x : data)
	{
		logFile << x << endl;
	}
}
template< class T > 
const int partition(vector<T> & data, int low, int high)
{
	//const int partitionIdx = static_cast<int>( (high + low) / 2 );
	//const int partitionIdx = (low + (high - low) / 2);
	const int partitionIdx = low;
	const T partitionVal = data[partitionIdx];
	cout<<"Partition pos: "<<partitionIdx<<" and value: "<<partitionVal<<endl;

	//Swap around partition value
	while (true)
	{
		while ( data[low] < partitionVal)
		{
			low++;
		}
		while ( data[high] > partitionVal)
		{
			high--;
		}
		if (low >= high)
		{
			return (high);
		}
		else
		{
			//SWAP
			cout<<"swap idx "<<low<<"="<<data[low]<<" with idx "<<high<<"="<<data[high]<<endl;
			T tmp = data[high];
			data[high] = data[low];
			data[low] = tmp;
			printData(data);
			low++;
			high--;
		}
	}
}

template< class T >
void quickSort(vector<T> & data, int low, int high)
{
	cout << "QUICKSORT: low " << low << " high " << high << endl;
	if (low < high )
	{
		const int partitionIdx = partition<T>(data, low, high);
		cout<<"PartitionIdx "<<partitionIdx<<endl;
		quickSort<T>(data, low, partitionIdx); // partition is now in correct place
		quickSort<T>(data, partitionIdx+1, high); // partition is now in correct place
	}
}


int main()
{
	//For no reason except refreshing, going to open a file, write to it, and close it
	ofstream logFile;
	logFile.open("quicksort.txt");
	logFile << "Quicksort begin\n";
	vector<int> data = {1, 6, 3, 19, 4};
	printData(data);
	logData(logFile, data);
	logFile << "Sorting data with quicksort\n";
	quickSort<int>(data, 0, data.size()-1);
	printData(data);
	logData(logFile, data);
	logFile.close();
	return 0;

}

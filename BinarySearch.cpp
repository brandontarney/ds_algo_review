/*
   Implements binary serach
   @date	08/26/2019
	@author	Brandon Tarney
	*/

#include <vector>
#include <iostream>
#include <cstdio>
#include <sstream>
#include <iterator>
#include <string>

using namespace std;

class Answer
{
	public:
		static bool binarySearch(vector<int> & vals, int low, int high, int val, int runItr)
		{
			if (runItr > 10)
			{
				return false;
			}
			int midPoint = static_cast<int>( (high + low) / 2);
			printf("low(%d), mid(%d), high(%d), val(%d), vals[mid](%d)\n", low, midPoint, high, val, vals[midPoint]);
			if (low == high && vals[low] != val)
			{
				cout<<"low is high and value ! contained, FALSE"<<endl;
				return false;
			}
			else if (vals[midPoint] == val)
			{
				cout<<"val[MidPoint] == val, TRUE"<<endl;
				return true;
			}
			else if (vals[midPoint] < val)
			{
				cout<<"vals[midPoint] < val"<<endl;
				return (binarySearch(vals, midPoint + 1, high, val, runItr+1));
			}
			else if (vals[midPoint] > val)
			{
				cout<<"vals[midPoint] > val"<<endl;
				return (binarySearch(vals, low,  midPoint, val, runItr+1));
			}
			else
			{
				cout<<"ERROR, this should be impossible, logging values"<<endl;
				printf("low(%d), mid(%d), high(%d), val(%d)\n",
						low, midPoint, high, val);
				return false;
			}
		};
};

int main()
{
	cout<<"Performing binary search on vetor inputs"<<endl;
	vector<int> input1 {1,2,3,4,5,6,7,8,9};
	ostringstream output;
	copy(input1.begin(), input1.end()-1, ostream_iterator<int>(output,","));
	output << input1.back();//so we don't have a trailing comma
	assert(false == false);
	cout<<"input1: "<<output.str()<<endl;
	const bool test1Found = Answer::binarySearch(input1, 0, input1.size()-1, 10, 1);
	const bool test2Found = Answer::binarySearch(input1, 0, input1.size()-1, 1, 1);
	const bool test3Found = Answer::binarySearch(input1, 0, input1.size()-1, 6, 1);
	assert(test1Found == false);
	assert(test2Found == true);
	assert(test3Found == true);
	return 0;
}


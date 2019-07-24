#!/bin/python

#NOTE - this is pseudocode, not real python code

#Algorithm
	#Sort based on the right-most column of a number (e.g. 982 = '2', then '8', then '9')
	#Counting sort the given 'digit'
	#Move left to the next column & repeat
	
	#NOTE - Counting sort:
		#Count the number of objects having distinct key values (kind of hashing)
		#Do arithmetic to calculate the position of each object in the output sequence
			#Sum counts at each index & prior indexes
			#Insert a value into sorted list starting from the end based on the count index & decrease the count index val 
			#Example:				
"""
For simplicity, consider the data in the range 0 to 9. 
Input data: 1, 4, 1, 2, 7, 5, 2
  1) Take a count array to store the count of each unique object.
  Index:     0  1  2  3  4  5  6  7  8  9
  Count:     0  2  2  0   1  1  0  1  0  0

  2) Modify the count array such that each element at each index 
  stores the sum of previous counts. 
  Index:     0  1  2  3  4  5  6  7  8  9
  Count:     0  2  4  4  5  6  6  7  7  7

The modified count array indicates the position of each object in 
the output sequence.
 
  3) Output each object from the input sequence followed by 
  decreasing its count by 1.
  Process the input data: 1, 4, 1, 2, 7, 5, 2. Position of 1 is 2.
  Put data 1 at index 2 in output. Decrease count by 1 to place 
  next data 1 at an index 1 smaller than this index.
"""
				
		
	
#Performance
	#ALL CASES O(n)

# Python program for implementation of Radix Sort 
  
# A function to do counting sort of arr[] according to 
# the digit represented by exp. 
def countingSort(arr, exp1): 
  
    n = len(arr) 
  
    # The output array elements that will have sorted arr 
    output = [0] * (n) 
  
    # initialize count array as 0 
    count = [0] * (10) 
  
    # Store count of occurrences in count[] 
    for i in range(0, n): 
        index = (arr[i]/exp1) 
        count[ (index)%10 ] += 1
  
    # Change count[i] so that count[i] now contains actual 
    #  position of this digit in output array 
    for i in range(1,10): 
        count[i] += count[i-1] 
  
    # Build the output array 
    i = n-1
    while i>=0: 
        index = (arr[i]/exp1) 
        output[ count[ (index)%10 ] - 1] = arr[i] 
        count[ (index)%10 ] -= 1
        i -= 1
  
    # Copying the output array to arr[], 
    # so that arr now contains sorted numbers 
    i = 0
    for i in range(0,len(arr)): 
        arr[i] = output[i] 
  
# Method to do Radix Sort 
def radixSort(arr): 
  
    # Find the maximum number to know number of digits 
    max1 = max(arr) 
  
    # Do counting sort for every digit. Note that instead 
    # of passing digit number, exp is passed. exp is 10^i 
    # where i is current digit number 
    exp = 1
    while max1/exp > 0: 
        countingSort(arr,exp) 
        exp *= 10
  

    
# driver code to test the above code 
if __name__ == '__main__': 
	# Driver code to test above 
	arr = [ 170, 45, 75, 90, 802, 24, 2, 66] 
	radixSort(arr) 
  
	for i in range(len(arr)): 
    	print(arr[i]), 
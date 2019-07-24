#!/bin/python

#NOTE - this is pseudocode, NOT python

#Algorithm
	#Find the largest value
	#Insert into list
	#Compare with other members of list & place in correct spot
	#Repeat
	#NOTE this is effectively iterating (inner loop) over the sorted list vs. selection sort iterating (inner loop) over the unsorted list
	
#Performance
	#AVG O(n^2), 
	#BEST O(n) - ordered data
	#WORST O(n^2) - reverse order
	
	
# Python program for implementation of Insertion Sort 
  
# Function to do insertion sort 
def insertionSort(arr): 
  
    # Traverse through 1 to len(arr) 
    for i in range(1, len(arr)): 
  		#Dealing with unsorted elements
        key = arr[i] 
  
        # Move elements of arr[0..i-1], that are 
        # greater than key, to one position ahead 
        # of their current position 
        #Dealing with sorted elements (shifting them to insert new value in sorted list)
        j = i-1
        while j >=0 and key < arr[j] : 
                arr[j+1] = arr[j] 
                j -= 1
        arr[j+1] = key 
  
  
# Driver code to test above 
arr = [12, 11, 13, 5, 6] 
insertionSort(arr) 
print ("Sorted array is:") 
for i in range(len(arr)): 
    print ("%d" %arr[i]) 
  
# This code is contributed by Mohit Kumra 
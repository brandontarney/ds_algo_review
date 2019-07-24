#!/bin/python

#NOTE - this is pseudocode, not real python code

#Algorithm
	#Create sorted sublist (usually in the front of the list)
	#Find the next smallest value and swap it into front position of a sorted sublist 
	#NOTE this is effectively iterating (inner loop) over the unsorted list vs. selection sort iterating (inner loop) over the sorted list
	
#Performance
	#AVG O(n log n) 
	#BEST O(n log n)
	#WORST O(n^2) - reverse order

#Form a sorted list starting at the front by simply swapping in the smallest value each iteration
def selection_sort( list ):
	for (i = 0; i < list.len; i++):
		min_val_idx = i
		for (j=i+1; j< list.len; j++):
			if (list[j] < list[min_val_idx]):
				min_val_idx = j
		
		#We found something smaller
		if (min_val_idx != i):
			tmpvar = list[i]
			list[i] = list[min_val_idx]
			list[min_val_idx] = tmpvar
	
		
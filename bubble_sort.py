#!/bin/python

#THIS IS PSEUDOCODE -

#Algorithm
	#Double nested loop
	#Swap next value if greater
	
#Performance
	#AVG O((n^2 + n) / 2), 
	#BEST O(n) - ordered data
	#WORST O(n^2 + n) - reverse order

def bubblesort( list_to_sort ):
	#POTENTIALLY make a pass for every item in the array (worst case O(n^2) 
	#	because items could be in inverse order e.g. [4, 3, 2, 1]
	# Note this includes an optimization to stop early with "swap_occured" variable
	#	becuase items could be nearly sorted e.g. [1, 2, 4, 3]
	for (i = 1; i < list_to_sort.len; i++):
		swap_occurred = false #Tracks if swap occured, end if no swap occurs
		for (j = (list_to_sort.len - 1); j > 0; j--): 
			#Check prior element vs. current element in array 
			if ( list_to_sort[j-1] > list_to_sort[j] ):
				#Swap them( element : list_to_sort):
				swap_var = list_to_sort[j-1]
				list_to_sort[j-1] = list_to_sort[j]
				list_to_sort[j] = swap_var
				swap_occured = true
		if (!swap_occurred):
			#No swap occured so this list is sorted
			break
		
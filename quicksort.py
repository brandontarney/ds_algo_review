#!/bin/python3

#NOTE - this is pseudocode so it may not run in the python interpreter

#Algorithm
	#Select pivot (value around which to pivot)
	#Assign down ptr to start of partition
	#Assign up ptr to end of partition
	#Move up ptr down if values are > pivot val
	#Move down ptr up if values are < pivot val
	#Swap down & up values if/when the above 2 conditions fail
	#repeat until up == down
	#Copy pivot into down/up ptr location (thus creating 2 partitions - above & below)
	#Repeat (recurse!) all steps on EACH partition 
	
#Performance
	#AVG O(n log n) 
	#BEST O(n log n)
	#WORST O(n^2) - reverse order

def quicksort( list, lo, hi ):
	#Create partition of values around an arbitrary pivot val
	partition_idx = partition(list, lo, hi) 
	#Recurse on each partitions
	quicksort(list, lo, partition_idx)
	quicksort(list, partition_idx+1, hi)
	
	
def partition( list, lo, hi ):
	#Choose pivot, best basic guess is mid val, ideal is median va
	
	#Effectively pick a pivot & ensure all values on 1 side are less than pivot & all values on other side are greater than pivot & return the dividing index
	pivot = list[ (hi + lo) / 2] 
	
	while (true):
		#Values which are less than pivot leave alone
		while list[lo] < pivot:
			lo = lo + 1
			
		#Value greater than pivot above pivot leave alone
		while list[hi] > pivot:
			hi = hi - 1
			
		#If low has reached high, then the partitioning is done
		if ( lo >= hi ):
			return hi
			
		#If you reach this block then low < hi & some value is > pivot on low side and some value is < pivot on high side
		#Swap lo & hi vals since they both do not conform 
		tmpvar = list[lo]
		list[lo] = list[hi]
		list[hi] = tmpvar
	
	
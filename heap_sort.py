#!/bin/python

#NOTE - this is not functioning python - it's merely pseudocode

#Algorithm
	# Build heap 
		#make sure all children are less than their parent - swap values in array
	# Generate sorted list 
		# remove the root by swapping it with inorder precessor (greatest value)
		# Resolve the tree (rework the hea via swaps to have correct root)


#Performance
	#AVG O(n log n)
	#BEST O(n log n)
	#WORST O(n^2)

def heapsort(list, count):
	#Build the heap so largest value at root
	heapify( list, count)
	end = count - 1
	while (end > 0):
		swap(list[end], list[0])
		end = end - 1
		#THe swap ruined the heap property, so restore it
		siftDown(list, 0, end)
		

def heapify(list, count):
	start = get_parent_index(count-1)
	while (start >= 0):
		siftDown(list, start, count-1)
		start = start - 1
	
def get_parent_index(idx):
	return idx/2
	
def get_left_child_index(idx, list):
	if (idx * 2 < list.len):
		return (idx * 2)
	else:
		return (-1)

def siftDown(list, start, end):
	root_idx = start
	#While the root has at least one child 
	while get_left_index(root, list) <= end):
		child_idx = get_left_index(root)
		swap_idx = root_idx
		#Check for left-child
		if (list[swap_idx] < list[child_idx]):
			swap_idx = child_idx
		
		#Check for right-child 
		if (child_idx+1 <= end and 
				list[swap] < list[child+1]):
				swap = child_idx+1
		if (swap == root):
			#The root holds the largest element. Since we assume the heaps rootate at the children are valid, this means we are done
			return
		else:
			swap(list[root], list[swap])
			root = swap
		
	
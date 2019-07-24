#!/usr/local/bin/python3
import math

class MinHeap:
	def __init__(self, input_list):
		self.heap_size = len(input_list)
		self.input_list = input_list
		self.heap_list = input_list
		self.heapify() #will operate on self.heap_list & create a heap in it

	#Construct & return a valid heap from heap_list
	def heapify(self):
		#Swap every element until its parent is smaller than itself
		for idx in range(self.heap_size, -1, -1):
			swap_up(idx)

	#Move value in heap_list[idx] up the heap until its parent is SMALLER than itself
	def sift_up(self, child_idx):
		if (child_idx == 0)
			return
		else:
			child_value = self.heap_list[child_idx]
			parent_idx = self.get_parent_idx(idx)
			parent_value = self.heap_list[parent_idx]
			#Check to see if you're the root of heap
			if (parent_value > child_value):
				self.swap(parent_idx, child_idx)
				child_idx = parent_idx
				self.sift_up(child_idx)

	#An alternative algorithm is to place EVERY item at the front at least once & then sift them down...
	def swap_down(

	#Swap the values of parent_idx & child_idx in self.heap_list
	def swap(self, parent_idx, child_idx):
		tmp_parent_value = self.heap_list[parent_idx]
		self.heap_list[parent_idx] = self.heap_list[child_idx]
		self.heap_list[child_idx] = tmp_parent_value




	#Return the parent index given input index idx
	def get_parent_idx(self, idx):
		#idx=3, 3/2 = 1.5 -> 2 - 1 = 1 
		#idx=1, 1/2 = 0.5 -> 1 - 1 = 0
		return (math.ceil(idx/2) - 1)



	#Construct a sorted list from self.heap_list and return it
	def heap_sort(self):
		print("UNIMPLEMENTED")
		return []

		


def main():
	tmp_file = open("heap_sort.tmp.log", "w")
	print("Starting heap_sort2.py")
	tmp_file.write("Starting heap_sort2.py")

	#Output starting list to stdou & file
	unsorted_list = [4, 8, 3, 1, 0, 5, 6, 9, 7, 2]
	print("unsorted list: ", str(unsorted_list))
	tmp_file.write("unsorted list:", str(unsorted_list))

	#Output heap to stdout & file
	heap = MinHeap(unsorted_list)
	print("Heap: ", str(heap.heap_list))
	tmp_file.write("Heap: ", str(heap.heap_list))

	#Output sorted list to stdout & file
	sorted_list = heap.heap_sort()
	print("Sorted list", str(sorted_list))
	tmp_file.write("Sorted list", str(sorted_list))

	tmp_file.close()


if "__name__" == "__main__":
	main()


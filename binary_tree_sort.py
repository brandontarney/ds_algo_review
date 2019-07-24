#!/bin/python

#NOTE - this is pseudocode, wont run with python interpreter


#Algorithm
	# Build general binary tree (log n)
	# Generate sorted list using inorder traversal (n)


#Performance
	#AVG O(n log n)
	#BEST O(n log n)
	#WORST O(n^2)


class Node:
	value
	left_child
	right_child
	
class BSTree:
	root
	
	def insertVal(value):
		this.insertNode(root, value)
		
	def insertNode(node, value):
		if (node == null)
			node = Node(value)
			return node
		
		if (value < root.value):
			root.left = this.insertNode(this.left, value)
		elif (value > root.value):
			root.right = this.insertNode(this.right, value)
		
		return node
		
	def inorderTraversal(root):
		#STOPPING POINT = no left child
		if (root != null):
			inorderTraversal(root.left)
			print(root)
			inorderTraversal(root.right)
			

def binary_sort( list ):
	#Build a binary tree = n * log n
	#	basically for every item 'n' insert it into the tree (log n)
	binary_sort_tree = BSTree()
	root = NULL
	for item in list:
		binary_sort_tree.insert(item)
		
	binary_sort_tree.inorderTraversal(binary_sort_tree)
		
	
		
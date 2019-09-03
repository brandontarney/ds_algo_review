#Algorithm
	#Find minimum spanning tree
	#Traverse the graph and decide along the way whether to include an edge in the spanning tree or not
	#	To include an edge, it must be 'safe' or it must be a minimum edge
	#Often a greedy approach is taken
	#Prim's algorithm uses a priority queue of vertexes with "weights" as the key to the priority_queueu....these weights are started as INF except for the root/start node which is 0. The highest priority node is extracted, it's adjacent vertexes are examined and their weights (keys) are updated based on the associated edge weeights from the node & ultimately the smallest value (greedy) is chosen! Don't forget to track predecessors as well
	#	Essentially this is like ordering all vertexes as weighted compared to the predecessor...and at first taht's unknown and therefore everything is assumed to be INF and as you greedily explore you update and take the best one but note you move to the next node BASED on this value


from queue import PriorityQueue

#Get the node
def get_node_idx( node_list, node_idx ):
	for idx in range(0, len(node_list)):
		if node_list[idx][0] == node_idx:
			return idx
	return -1


def get_min_weight_node_idx( nodes_by_min_weight ):
	min_weight_node = (-1, 9999)
	min_weight_node_idx = -1
	for idx in range(0, len(nodes_by_min_weight)):
		if nodes_by_min_weight[idx][1] < min_weight_node[1]:
			min_weight_node = nodes_by_min_weight[idx]
			min_weight_node_idx = idx
	return min_weight_node_idx



#Find the min spanning tree
#Effectively, track the nodes by min weight & constantly select the next one available
def find_min_span_tree(graph, start_node_idx, debug=False):
	nodes_by_min_weight = []
	start_weight = 9999
	if debug:
		print('graph', graph)
	#Initiatlize all nodes to be super far (basically unknown so assume the worst)
	for node_idx in range(0, len(graph)):
		nodes_by_min_weight.append( (node_idx, start_weight) )
	#Initiatlize the start node to be 0 distance because you're starting there
	min_weight_start_node_idx = get_node_idx( nodes_by_min_weight, start_node_idx)
	nodes_by_min_weight[min_weight_start_node_idx] = (start_node_idx, 0)

	#Spanning tree begins empty
	min_spanning_tree = []

	while len(nodes_by_min_weight) > 0:
		#Get the min weight node
		min_weight_node_idx = get_min_weight_node_idx(nodes_by_min_weight)
		min_weight_node = nodes_by_min_weight[min_weight_node_idx]
		if debug:
			print('chosen node', min_weight_node)
		#Add the node to the min_spanning_tree
		min_spanning_tree.append(min_weight_node)

		#Updatea adjacent node weights in nodes_by_min_weight AS LONG as they aren't in min_spanning_tree 
		adjacent_graph_nodes = graph[min_weight_node[0]]
		for adjacent_node in adjacent_graph_nodes:
			if get_node_idx(min_spanning_tree, adjacent_node[0]) == -1:
				current_node_weight_idx = get_node_idx(nodes_by_min_weight, adjacent_node[0])
				current_node_by_weight = nodes_by_min_weight[current_node_weight_idx]
				if debug:
					print('min_spanning_tree', min_spanning_tree)
					print('nodes_by_min_weight', nodes_by_min_weight)
					print('adjacent node', adjacent_node)
					print('current_node_by_weight_idx ', current_node_weight_idx)
					print('current_node_by_weight ', current_node_by_weight)
				if current_node_by_weight[1] > adjacent_node[1]:
					nodes_by_min_weight[current_node_weight_idx] = adjacent_node


		#Remove node from list of nodes_by_min_weight
		if debug:
			print("remove node: ", min_weight_node)
		nodes_by_min_weight.remove(min_weight_node)

	return min_spanning_tree



def main():
	print('MIN SPANNING TREE - PRIM ALGO')
	'''
		0
	  11  12
	1   13   2
	  14   15
		3
	'''
	#Undirected Graph as adjacency lists with weights 
	graph = [ \
			[(1, 11), (2, 12)], \
			[(0, 11), (2, 13), (3, 14)], \
			[(0, 12), (1, 13), (3, 15)], \
			[(1, 14), (2, 15)] \
			]

	#Expected min spannin tree is list of tuples with each vertex chosen & the associated weight (min weight) of that tree
	#Assume we start at vertex 0
	expected_min_spanning_tree = [ (0, 0), (1, 11), (2, 12), (3, 14) ]
	print("expected min_spanning_tree: ", expected_min_spanning_tree)

	start_node = 0
	min_spanning_tree = find_min_span_tree(graph, start_node)
	print("min_spanning_tree: ", min_spanning_tree)


if __name__ == "__main__":
	main()

'''

#CONTRIBUTED FROM GEEKS FOR GEEKS

# A Python program for Prim's Minimum Spanning Tree (MST) algorithm.
# The program is for adjacency matrix representation of the graph

import sys # Library for INT_MAX

class Graph():

    def __init__(self, vertices):
        self.V = vertices
        self.graph = [[0 for column in range(vertices)]
                    for row in range(vertices)]

    # A utility function to print the constructed MST stored in parent[]
    def printMST(self, parent):
        print "Edge \tWeight"
        for i in range(1, self.V):
            print parent[i], "-", i, "\t", self.graph[i][ parent[i] ]

    # A utility function to find the vertex with
    # minimum distance value, from the set of vertices
    # not yet included in shortest path tree
    def minKey(self, key, mstSet):

        # Initilaize min value
        min = sys.maxint

        for v in range(self.V):
            if key[v] < min and mstSet[v] == False:
                min = key[v]
                min_index = v

        return min_index

    # Function to construct and print MST for a graph
    # represented using adjacency matrix representation
    def primMST(self):

        # Key values used to pick minimum weight edge in cut
        key = [sys.maxint] * self.V
        parent = [None] * self.V # Array to store constructed MST
        # Make key 0 so that this vertex is picked as first vertex
        key[0] = 0
        mstSet = [False] * self.V

        parent[0] = -1 # First node is always the root of

        for cout in range(self.V):

            # Pick the minimum distance vertex from
            # the set of vertices not yet processed.
            # u is always equal to src in first iteration
            u = self.minKey(key, mstSet)

            # Put the minimum distance vertex in
            # the shortest path tree
            mstSet[u] = True

            # Update dist value of the adjacent vertices
            # of the picked vertex only if the current
            # distance is greater than new distance and
            # the vertex in not in the shotest path tree
            for v in range(self.V):
                # graph[u][v] is non zero only for adjacent vertices of m
                # mstSet[v] is false for vertices not yet included in MST
                # Update the key only if graph[u][v] is smaller than key[v]
                if self.graph[u][v] > 0 and mstSet[v] == False and key[v] > self.graph[u][v]:
                        key[v] = self.graph[u][v]
                        parent[v] = u

        self.printMST(parent)

g = Graph(5)
g.graph = [ [0, 2, 0, 6, 0],
            [2, 0, 3, 8, 5],
            [0, 3, 0, 0, 7],
            [6, 8, 0, 0, 9],
            [0, 5, 7, 9, 0]]

g.primMST();

# Contributed by Divyanshu Mehta
'''
	

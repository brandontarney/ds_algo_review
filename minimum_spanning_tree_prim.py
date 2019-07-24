#Algorithm
	#Find minimum spanning tree
	#Traverse the graph and decide along the way whether to include an edge in the spanning tree or not
	#	To include an edge, it must be 'safe' or it must be a minimum edge
	#Often a greedy approach is taken
	#Prim's algorithm uses a priority queue of vertexes with "weights" as the key to the priority_queueu....these weights are started as INF except for the root/start node which is 0. The highest priority node is extracted, it's adjacent vertexes are examined and their weights (keys) are updated based on the associated edge weeights from the node & ultimately the smallest value (greedy) is chosen! Don't forget to track predecessors as well
	#	Essentially this is like ordering all vertexes as weighted compared to the predecessor...and at first taht's unknown and therefore everything is assumed to be INF and as you greedily explore you update and take the best one but note you move to the next node BASED on this value

#NOTE this is pseudocode

def find_min_span_tree(graph):
	priority_queue = Queue(graph.vertexes) #abbreviated call 
	for vertex in priority_queue:
		key[vertex] = 99999999
	#Select a root - could be provided or arbitrary
	root = rand(priority_queue)
	key[root] = 0
	predecessor[root] = -1
	while (not priority_queue.empty):
		vertex = extract_min(priority_queue) #This will start by being the root because we set it to 0 & become the smallest adjacent weighted edge->vertex after every iteration
		for adjacent_vertex in graph[vertex]:
			#This is basically the definiton of a safe edge!
			if priority_queue.contains(adjacent_vertex) and 
				(graph[vertex][adjacent_vertex].weight < key[adjacent_vertex]):
					predecessor[adjacent_vertex] = vertex
					key[adjacent_vertex] = graph[vertex][adjacent_vertex].weight



def main():
	print('do stuff')
	'''
		1
	2   -   3
		4
	'''
	#using adjacency list...
	graph = { 1:[2,3], 2:[3,4], 3:[2,4], 4:[2,3] }
	min_spanning_tree = find_min_span_tree(graph)


if "__name__" == "__main__":
	main()


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
	

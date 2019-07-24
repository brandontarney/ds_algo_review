#NOTE: this may not compile/run - it's probably just pseudocode

# Breadth-first explores all vertexes of a graph as a form of searching the graph
# 	Queue the vertexes visited in a BFS - order, meaning every adjacent vertex is visited prior to visiting any other vertex in the graph 

# vertex = u
# pi(u) = predecessor of u
# d[u] = distance (e.g. cost) from source vertex 's'
# color[u] = {white (not discovered), gray (discovered but not fully explored), blue (search algo finished exploringall options from this vertex)}
from enum import Enum

class Color(Enum):
	white = 1
	gray = 2
	blue = 3
	
	
def breadth_first_search(graph, start_vertex):
	size_of_graph = len(graph)
	vertex_colors, distance_from_start, vertex_predecessor = list()
	
	for vertex_idx in range(size_of_graph):
		vertex_colors[vertex_idx] = Color.white
		vertex_predecessor[vertex_idx] = 999999
		vertex_predecessor[vertex_idx] = None
	
	vertex_colors[start_vertex] = Color.gray
	vertex_distance[start_vertex] = 0
	vertex_predecessor[start_vertex] = None
	
	visited_vertex = Queue(start_vertex)
	
	while (!visited_vertex.empty()):
		vertex = visited_vertex.get()
		visited_vertex.put(vertex) #This is to approximate the "head()" method
		for adjacent_idx in len(graph[vertex]):
			if vertex_colors[adjacent_idx] == Color.white:
				vertex_colors[adjacent_idx] = Color.gray
				vertex_distance[adjacent_idx] = vertex_distance[vertex] + 1
				vertex_predecessor[adjacent_idx] = vertex
				visited_vertex.put(adjacent_idx)	
		visited_vertex.get() #remove this node, it's been totally visited	
		vertex_colors[vertex] = Color.blue

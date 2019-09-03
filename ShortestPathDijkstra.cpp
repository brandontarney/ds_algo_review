//NOTE - this may not be valid code

/*
* Algorithm
*   Find the minimum weighted path in a directed graph from the source to the destination
		- implies that every vertex is a descendant of source vertex
*	Dijkstra algorithm 
		- all weights non-negative, use priority_queue, assume graph is adjacency lists, 
			set shortest path estimate for all vertices other than source to INF,
			set all predecessors to NIL, shortest path estimate source = 0
		- Choose the minium distance value vector
		- Update the DISTANCE value for each ADJACENT vector each time a vector is chosen if less than previous minimum
 */

#include<fstream> //<ofstream> & others for files
#include<iostream> //CIN/COUT
#include<algorithm> //basic algorithms
#include<cstdio> //printf & File class
#include<cstdlib> // memory management numeric string converstion, 
#include<list>
#include<priority_queue>
#include<utility>

using namespace std;

const int getMinIndexFromQueue( vertex<int> vertexQueue


const bool isNodeInList(list<pair<int,int>> & nodeList, const int nodeIdx)
{
	for (auto & node : nodeList)
	{
		if (node.second == nodeIdx)
		{
			return true;
		}
	}
	return false
}

const int getMinVertexDistanceIdx( vector<int> & vertexDistances )
{
	int minVal = 9999;
	int minIdx = -1;
	for ( int i = 0; i < vertexDistances.size(); i++)
	{
		if (minVal > vertexDistances[i])
		{
			minVal = vertexDistances[i];
			minIdx = i;
		}
	}
	return minIdx;
}

list<pair<int, int>> findShortestPathDijkstra(vertex<vertex<pair<int,int>>> & graph, const int startNodeIdx, const int endNodeIdx)
{
	vertex<int> vertexDistances; //index is node, value is distance 
	vertex<int> prevNode; //Index to previous node in this min path
	vertex<int> exploredState; //Keeps track of those nodes chosen
	
	for (int nodeIdx = 0; nodeIdx < graph.size(); nodeIdx++)
	{
		vertexDistance[nodeIdx] = 9999;
		prevNode[nodeIdx] = -1; //This indicates it is NOT in the min path
		exploredState[nodeIdx] = -1; //This value will be 1 if it's been explored
	}
	//Initiatlize start node index to be smallest value
	vertexDistances[startNodeIdx] = 0; 
	
	while (!vertexDistances.empty())
	{
		currentVertex = getMinVertexDistance(vertexDistances);
		if (currentVertex == endNodeIdx)
		{
			cout<<"Found the end node, so I must have a min path"<<endl;
			break;
		}

		for (auto & adjacentVertexPair : graph[nextVertex])
		{
			//Calculate the distance from start node for each adjacent node - update any who are shortest AND not already chosen vertex list
			adjacentVertex = adjacentVertexPair.second;
			if (exploredState[adjacentVertex] == -1)
			{
				adjacentVertexDistance = vertexDistances[currentVertex] + adjacentvertexPair.first;
				if (vertexDistances[adjacentVertex] > adjacentVertexDistance)
				{
					vertexDistances[adjacentVertex] = adjacentVertexDistance;
					prevNode[adjacentVertex] = currentVertex;
				}
			}
		}
		exploredState[currentVertex] = 1;
		
	}

}

template<class SequenceOfPairs>
void printSequencePair(SequenceOfPairs & sequenceOfPairs)
{
	for (auto tmpPair = sequenceOfPairs.begin(); tmpPair != sequenceOfPairs.end(); ++tmpPair)
    {
    	std::cout << tmpPair->first << ',' << tmpPair->second<<endl;
    }
    
}

int main()
{
/*
		0
	  11  12
	1   2   2
	  14   2
		3
*/
	vector<vector<pair<int, int>>> graph = {
			{(11, 1), (12, 2)}, \
			{(11, 0), (8, 2), (14, 3)}, \
			{(12, 0), (8, 1), (2, 3)}, \
			{(14, 1), (2, 2)} \
			};
	const int startNodeIdx = 0;
	const int endNodeIdx = 3;
	list<pair<int, int>> shortestPath = 
		findShortestPathDijkstra(graph, startNodeIdx, endNodeIdx);
		
	cout<<"Expected path:"<<endl;
	cout<<"3,2,1,0"<<endl;
	printSequencePair<list<pair<int,int>>(shortestPath);
}

/*
   CODE FROM GEEKS FOR GEEKS

// A C++ program for Dijkstra's single source shortest path algorithm.
// The program is for adjacency matrix representation of the graph

#include <stdio.h>
#include <limits.h>

// Number of vertices in the graph
#define V 9

// A utility function to find the vertex with minimum distance value, from
// the set of vertices not yet included in shortest path tree
int minDistance(int dist[], bool sptSet[])
{
   // Initialize min value
   int min = INT_MAX, min_index;

   for (int v = 0; v < V; v++)
     if (sptSet[v] == false && dist[v] <= min)
         min = dist[v], min_index = v;

   return min_index;
}

// A utility function to print the constructed distance array
int printSolution(int dist[], int n)
{
   printf("Vertex   Distance from Source\n");
   for (int i = 0; i < V; i++)
      printf("%d tt %d\n", i, dist[i]);
}

// Function that implements Dijkstra's single source shortest path algorithm
// for a graph represented using adjacency matrix representation
void dijkstra(int graph[V][V], int src)
{
     int dist[V];     // The output array.  dist[i] will hold the shortest
                      // distance from src to i

     bool sptSet[V]; // sptSet[i] will be true if vertex i is included in shortest
                     // path tree or shortest distance from src to i is finalized

     // Initialize all distances as INFINITE and stpSet[] as false
     for (int i = 0; i < V; i++)
        dist[i] = INT_MAX, sptSet[i] = false;

     // Distance of source vertex from itself is always 0
     dist[src] = 0;

     // Find shortest path for all vertices
     for (int count = 0; count < V-1; count++)
     {
       // Pick the minimum distance vertex from the set of vertices not
       // yet processed. u is always equal to src in the first iteration.
       int u = minDistance(dist, sptSet);

       // Mark the picked vertex as processed
       sptSet[u] = true;

       // Update dist value of the adjacent vertices of the picked vertex.
       for (int v = 0; v < V; v++)

         // Update dist[v] only if is not in sptSet, there is an edge from
         // u to v, and total weight of path from src to  v through u is
         // smaller than current value of dist[v]
         if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX
                                       && dist[u]+graph[u][v] < dist[v])
            dist[v] = dist[u] + graph[u][v];
     }

     // print the constructed distance array
     printSolution(dist, V);
}

// driver program to test above function
int main()
{
   // Let us create the example graph discussed above 
   int graph[V][V] = {{0, 4, 0, 0, 0, 0, 0, 8, 0},
                      {4, 0, 8, 0, 0, 0, 0, 11, 0},
                      {0, 8, 0, 7, 0, 4, 0, 0, 2},
                      {0, 0, 7, 0, 9, 14, 0, 0, 0},
                      {0, 0, 0, 9, 0, 10, 0, 0, 0},
                      {0, 0, 4, 14, 10, 0, 2, 0, 0},
                      {0, 0, 0, 0, 0, 2, 0, 1, 6},
                      {8, 11, 0, 0, 0, 0, 1, 0, 7},
                      {0, 0, 2, 0, 0, 0, 6, 7, 0}
                     };

    dijkstra(graph, 0);

    return 0;
}
*/